#include <LiquidCrystal.h>
LiquidCrystal lcd(2,4,5,6,7,8);
char Rec_Data=0;
char msg_flg=0;
char msg_flag_2=0;
char call_flag=0;
char reply_flag=0;
char delete_flag=0;
char d_count=0;
char i=0;
char j=0;
char number[15];
char message[160];
void modem_initialization(void);
void gsm_send_message(void);
void clear_rx_buffer(void);
void setup()
{
  delay(1000);
  Serial.begin(9600);//start serial port at baud rate of 9600 
  delay(1000);
  delay(1000);
  //lcd.print("GSM Initialising      ");   
  modem_initialization();
  Serial.print("GSM Initialised       ");
}
void loop()
{   
gsm_read_message();//wait for message or call
if( reply_flag == 1 )//only if valid message received
 {
    lcd.clear();
    lcd.setCursor(0,0);lcd.print(number); 
    lcd.setCursor(0,1);lcd.print(message); 
    gsm_send_message();
  }
}
/**********************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************
Function Name : GSM_SEND_MESSAGE
Function used to send message  
Variables :-
 sent           :To check the status of message sending process
 reply_flag     :Must be cleared ,no need to check after a meessage
 send_flag      :To ensure sucessful messge which is cleared only after message sent
 msg_flg        :To check message reading steps
 task_control   :To prevent other functions execution in the time of sending message
Arguments :-
            No arguments
Return    :-
            No returns
***********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************/
void gsm_send_message(void)
{
char send_flag=1;
char msg_flg=0;
char rec_data=0;
delay(300);
clear_rx_buffer();//clearing receiving buffer
Serial.print("AT+CMGS=");//Command to send message ,(AT+CMGS="+91phone number"<enter>)
Serial.print('"'); 
Serial.print(number);
Serial.println('"'); 
while(send_flag == 1)
{
 while(Serial.available() > 0)  
 {
 rec_data = Serial.read();
 if(rec_data =='>')//'>'(greater than symbol) is received while message sending,after AT+CMGD="number" command
 {
  delay(400);//Delay for GSM module become ready
  Serial.print(" MESSAGE RECEIVED AND DISPLAYED IN LCD,THANK YOU");//Transmitting whole string to be sent as SMS 
  Serial.write(26);//'ctrl+z' command
  delay(300);//Delay for GSM module become ready
  msg_flg=0;
 } 
 else if(rec_data == '+' && msg_flg == 0 )//'+' is received                   
   msg_flg = 1 ;   
 else if(rec_data == 'C' && msg_flg == 1 )//'C' is received
   msg_flg = 2 ;
 else if(rec_data == 'M' && msg_flg == 2 )//'M' is received
   msg_flg = 3 ;
 else if(rec_data == 'G' && msg_flg == 3 )//'G' is received
   msg_flg = 4 ;
 else if(rec_data == 'S' && msg_flg == 4 )//'S' is received after a successful message("+CMSGS:  ")
   msg_flg = 5 ;
 else if(rec_data == ':' && msg_flg == 5 )// ':' is received
   msg_flg = 6 ;
 else if(rec_data == 0x0D && msg_flg == 6 )//Carriage return
   msg_flg = 7 ;
 else if(rec_data == 0x0A && msg_flg == 7 )//Line feed
   msg_flg = 8 ;
 else if(rec_data == '0' && msg_flg == 8 )// '0' (zero) is received
 {
   clear_rx_buffer();//clearing receiving buffer
     msg_flg=0;
     msg_flag_2=0;
     send_flag=0;
     reply_flag=0;
  }
 else if ( rec_data == '4' && msg_flg == 0  )// '4' (zero) is received
 {
  clear_rx_buffer();//clearing receiving buffer
    msg_flg=0;
    msg_flag_2=0;
    send_flag=0;
    reply_flag=0;
 }
else if( Rec_Data == '2' && msg_flg == 0 )// '2' is received,incoming call
{
 call_flag=1; 
 delay(300);
 Serial.println("ATH");//Command for hang up incoming call,all calls must be filtered no need to answer a call 
}  
else if( Rec_Data=='0' && msg_flg == 0 && call_flag == 1 )// '0' (zero) is received,call successfully rejected
{
     msg_flg=0;
     call_flag=0;
     msg_flag_2=0;
     d_count=0;
     send_flag=0;
     reply_flag=0;
 }
 
 }
 }
}
void modem_initialization(void)
{
  char rec_data;
  char network_status = 0 ;//network_status initialized as zero
  char status_check = 0 ;//status_check initialized as zero
  char gsm_cnt = 0;//gsm_cnt initialized as zero
  char ok_flag=0;//ok_flag initialized as zero
  char count=0;//count initialized as zero
  clear_rx_buffer();//clearing receiving buffer
  while(gsm_cnt < 5)// repeat entire loop until gsm_cnt less than seven 
  {                                  
   switch(gsm_cnt)
   {
     case 0: clear_rx_buffer();//clearing receiving buffer 
     Serial.println("AT");// Attention command to wake up GSM modem
     delay(1000);
     break;
     case 1: clear_rx_buffer();//clearing receiving buffer
     Serial.println("ATE0");//Command for disable echo 
     delay(1000);
     break;
     case 2: clear_rx_buffer();//clearing receiving buffer
     Serial.println("ATV0");// Command for numeric response after this '0'(zero) will be recieved instead of "OK"
     delay(1000);
     break; 
     case 3: clear_rx_buffer();//clearing receiving buffer
     Serial.println("AT&W");// Command TO SAVE SETTINGS
     delay(1000);
     break;     
     case 4: gsm_cnt = 5;// exit from the loop
     break;
     default :break;
   }    
 while(Serial.available() > 0)
 {                   
   rec_data = Serial.read();
   if(rec_data == 'O' )// 'o' is received 
   ok_flag = 1;
  else if(ok_flag == 1 && rec_data == 'K' )// 'K' is received
  {
   gsm_cnt ++;
   ok_flag = 0;
  }
  else if (rec_data == '0' )// '0'(zero) is received (numeric response)
  {
    gsm_cnt ++;
    ok_flag = 0; 
  }
  else if (rec_data == '+' )// '+' is received message 
  {
    clear_rx_buffer();//clearing receiving buffer
    if( gsm_cnt > 0 )
     gsm_cnt --;
  }
 }
}
//lcd.setCursor(0,0);
Serial.println("GSM Modem Found  "); 
gsm_cnt = 0;
ok_flag = 0;
while(network_status == 0 )//wait for PIN READY
{
   if(status_check == 0 )
   {
    delay(1000);
    status_check = 1 ;
    clear_rx_buffer();//clearing receiving buffer
    Serial.println("AT+CPIN?"); //checking PIN return ready(+CPIN: READY) with a valid simcard otherwise error
   }
   while(Serial.available() > 0)  
   {
     rec_data = Serial.read();
     if( rec_data == '+' && status_check == 1 )// '+' is received
     status_check = 2 ;
     else if( rec_data == 'C' && status_check == 2 )// 'C' is received
     status_check = 3 ;
     else if( rec_data == 'P' && status_check == 3 )// 'P' is received
     status_check = 4 ;
     else if( rec_data == 'I' && status_check == 4 )// 'I' is received
     status_check = 5 ;
     else if( rec_data == 'N' && status_check == 5 )// 'N' is received
     status_check = 6 ;
     else if( rec_data == ':' && status_check == 6 )// ':' is received
     status_check = 7 ;
     else if( rec_data == ' ' && status_check == 7 )// ' ' is received
     status_check = 8 ;
     else if( rec_data == 'R' && status_check == 8 )// 'R' is received
     status_check = 9 ;
     else if( rec_data == 'E' && status_check == 9 )// 'E' is received
     status_check = 10 ;
     else if( rec_data == 'A' && status_check == 10 )// 'A' is received
     status_check = 11 ;
     else if( rec_data == 'D' && status_check == 11 )// 'D' is received
     status_check = 12 ;
     else if( rec_data == 'Y' && status_check == 12 )// 'Y' is received
     status_check = 13 ;
     else if( rec_data == 0X0D && status_check == 13 )//Carriage return
     status_check = 14 ;
     else if( rec_data == 0X0A && status_check == 14 )//Line Feed
     status_check = 15 ;
     else if( rec_data == '0' && status_check == 15 )// '0' is received
     {
      clear_rx_buffer();//clearing receiving buffer
      status_check = 0 ;
      network_status=1;//goto next step
     }
     else if( rec_data != 'R' && status_check == 8 )//+CPIN: NOT READY
     {
       clear_rx_buffer();//clearing receiving buffer
       status_check = 0 ;
       network_status=0;//repeat current step
     }
     else if( rec_data == 'M' && status_check == 3 )// in case of any message
     {
       clear_rx_buffer();//clearing receiving buffer
       status_check = 0 ;
       network_status=0;//repeat current step
     }
 
   }
 
}
//lcd.setCursor(0,0);
Serial.println("CPIN: Ready         ");
while(network_status == 1 )//wait for SIM network registration
{
  if(status_check == 0 )
  { 
     delay(1000);
     status_check = 1 ;
     clear_rx_buffer();//clearing receiving buffer
     Serial.println("AT+CREG?"); //checking for SIM card registration ,if registered "+CREG: 0,1" will receive
  }
  while(Serial.available() > 0)  
  {
     rec_data = Serial.read();
     if( rec_data == '+' && status_check == 1 )// '+' is received
     status_check = 2 ;
     else if( rec_data == 'C' && status_check == 2 )// 'C' is received
     status_check = 3 ;
     else if( rec_data == 'R' && status_check == 3 )// 'R' is received
     status_check = 4 ;
     else if( rec_data == 'E' && status_check == 4 )// 'E' is received
     status_check = 5 ;
     else if( rec_data == 'G' && status_check == 5 )// 'G' is received
     status_check = 6 ;
     else if( rec_data == ':' && status_check == 6 )// ':' is received
     status_check = 7 ;
     else if( rec_data == ' ' && status_check == 7 )// ' ' is received
     status_check = 8 ;
     else if( rec_data == '0' && status_check == 8 )// '0' is received
     status_check = 9 ;
     else if( rec_data == ',' && status_check == 9 )// ',' is received
     status_check = 10 ;
     else if( rec_data == '1' && status_check == 10 )// '1' is received
     status_check = 11 ;
     else if( rec_data == 0X0D && status_check == 11 )//Carriage return
     status_check = 12 ;
     else if( rec_data == 0X0A && status_check == 12 )//Line Feed
     status_check = 13 ;
     else if( rec_data == '0' && status_check == 13 )// '0' is received
     {
         clear_rx_buffer();//clearing receiving buffer
         status_check = 0 ;
         network_status=2;//goto next step
     }
     else if( rec_data != '1' && status_check == 10 )// +CREG: 0,2 not registered
     {
         clear_rx_buffer();//clearing receiving buffer
         status_check = 0 ;
         network_status=1;//repeat current step
     }
     else if( rec_data == 'M' && status_check == 3 )// in case of any message
     {
         clear_rx_buffer();//clearing receiving buffer
         status_check = 0 ;
         network_status=1;//repeat current step
     }
   }
 }
 gsm_cnt=0; 
 //lcd.setCursor(0,0);
 Serial.println("Registration Ok       ");  
 while(gsm_cnt < 4)// repeat entire loop until gsm_cnt less than nine
 { 
     switch(gsm_cnt)
     {
          case 0: clear_rx_buffer();//clearing receiving buffer
          Serial.println("AT+CMGF=1");// Attention command to wake up GSM modem
          delay(1000);
          break;
          case 1: clear_rx_buffer();//clearing receiving buffer
          Serial.println("AT+CNMI=2,1,0,0,0");//Command to configure new message indication
          delay(1000);
          break;
          case 2: clear_rx_buffer();//clearing receiving buffer
          Serial.println("AT+CMGD=1,4");// Command to delete all received messages 
          delay(1000);
          break;
          case 3: gsm_cnt = 4;// exit from the loop
          break;
          default :break;
     }    
     while(Serial.available() > 0)
     {                   
          rec_data = Serial.read();
          if (rec_data == '0' )// '0'(zero) is received (numeric response)
          {
             gsm_cnt ++;
          }
         else if (rec_data == '+'  )// '+' received ,before "AT+CIICR" command,may be any message
         {
            clear_rx_buffer();//clearing receiving buffer
            if( gsm_cnt > 0 )
            gsm_cnt --;
         }
        else if (rec_data == '4' && gsm_cnt > 2)// '4' received (error),in gprs initialization commands
         {
            clear_rx_buffer();//clearing receiving buffer
            gsm_cnt = 4;
         }  
      }
  }
 gsm_cnt = 0;
}
/**********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************
Function Name : CLEAR_RX_BUFFER
Function used to clear receiving buffer
Variables :-
            rec_data        :variable which hold received data
Arguments :-
            No arguments
Return    :-
            No returns
***********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************/
 
void clear_rx_buffer(void)
{
char rec_data=0;
while(Serial.available() > 0) 
rec_data = Serial.read();  
}
/**********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************
Function Name : GSM_READ_MESSAGE
Function used to read message from GSM module (only if any message is available ) 
Variables :-
            Rec_Data   :To receive data char fro GSM module
            msg_flg    :To check message reading steps
            d_count    :To count number of double quotes
            i          :array index
            j          :array index
            msg_flg_2  :set only when message message contain a '*'
            reply_flag :set only when message is in between '*' and '#'(valid message to check)
            sent       :To check message sending steps 
            call_flag  :Set when a call to Gsm modem occur
            send_flag  :To check whether message is sent or not
            conc_count :Cleared after sending a message (variable used for concatenation)
            number[]   :Number from which message received
            message[]  :Received message 
Arguments :-
            No arguments
Return    :-
            No returns
***********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************/
void gsm_read_message(void)
{    
while(Serial.available() > 0)  
 {
    Rec_Data = Serial.read();
    if( Rec_Data == '+'  && msg_flg == 0 )// '+' is recieved                
    msg_flg=1;       
    else if( Rec_Data == 'C' && msg_flg == 1 )// 'C' is recieved
    msg_flg=2;
    else if( Rec_Data == 'M' && msg_flg == 2 )// 'M' is recieved
    msg_flg=3;
    else if( Rec_Data == 'T' && msg_flg == 2 )// 'M' is recieved
    msg_flg=3; 
    else if( Rec_Data == 'I' && msg_flg == 3 )// ':' is recieved (INCOMING MESSAGE )
    {
        clear_rx_buffer();//clearing receiving buffer
        Rec_Data =0;
        msg_flg=0;
        delay(300);//Delay for GSM module become ready 
        array_clear();//Clear both message and number arrays
        Serial.println("AT+CMGR=1");//Command for message read from location one
        i=0;j=0; 
    } 
   else if( Rec_Data== 'G' && msg_flg == 3 )// 'M' is recieved
   msg_flg=4;
   else if( Rec_Data== 'R' && msg_flg == 4 )// 'r' is recieved,Readind message
   msg_flg=5;
   else if( Rec_Data== ':' && msg_flg == 5 )// ':' is recieved
   msg_flg=6; 
   else if( Rec_Data == '"' && msg_flg == 6  )// Counting double quotes
   d_count++;
   else if( Rec_Data != '"' && d_count==3 && msg_flg == 6)// Saving number to message array from between third and fourth double quotes
   number[i++] = Rec_Data;
   else if( Rec_Data== 0X0D && msg_flg==6)//Carriage return
   msg_flg=7;
   else if( Rec_Data== 0X0A && msg_flg==7)//Line feed
   msg_flg=8;
   else if( Rec_Data=='*' && d_count>=5 &&  msg_flg == 8 )//Start symbol '*' is recieved
   msg_flag_2=1;
   else if( Rec_Data!='#' && msg_flag_2 == 1 &&  msg_flg == 8 && Rec_Data!=0X0D && Rec_Data!=0X0A )//Data between start and stop symbols were saved to message array
   message[j++]=Rec_Data;
   else if( Rec_Data=='#' && msg_flag_2 == 1 &&  msg_flg == 8)//Stop symbol '#' is recieved 
   {    
      msg_flag_2 = 2;
      number[i]='\0';
      message[j]='\0';
      i=0;j=0; 
   }        
   else if(Rec_Data == 0X0D && msg_flg == 8)//Carriage return (end of message)
   {
      clear_rx_buffer();//clearing receiving buffer
      msg_flg=0;
      delete_flag=1;
      delay(300);//Delay for GSM module become ready
      Serial.println("AT+CMGD=1,4");// Command for delete all messages in SIM card
   }
   else if( Rec_Data == '0' && msg_flg == 0 && delete_flag == 1 )//Response for delete command ,sucess all messages were deleted
   {
     if( msg_flag_2 == 2 )
     reply_flag = 1;//If the message have start and stop symbols it must be checked otherwise no need to check the recieved message
     else  
     reply_flag = 0;//No need to check recieved message 
     msg_flg=0;
     msg_flag_2=0;
     d_count=0;
     delete_flag=0;
  }
  else if( Rec_Data == '2' && msg_flg == 0 )// '2' is recieved,incoming call
  {
     call_flag=1; 
     delay(300);
     Serial.println("ATH");//Command for hang up incomming call,all calls must be filtered no need to answer a call 
  }  
  else if( Rec_Data=='0' && msg_flg == 0 && call_flag == 1 )// '0' (zero) is recieved,call sucessfully rejected
  {
     msg_flg=0;
     call_flag=0;
     msg_flag_2=0;
     d_count=0;
     reply_flag=0;
  }
  else if( (Rec_Data == '3' || Rec_Data == '4' || Rec_Data == '7'  ) && msg_flg == 0 )//incase of any error,nocarrier and busy 
  {
     msg_flg=0;
     call_flag=0;
     msg_flag_2=0;
     d_count=0;
     reply_flag=0;
  }
 
 }
}
/**********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************
Function Name : ARRAY_CLEAR
Function used to clearing message,user_id and number arrays
Variables :-
            k        :array index
Arguments :-
            No arguments
Return    :-
            No returns
***********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************************/
void array_clear(void)
{
  char k=0;  
  for( k=0;k<=15;k++)
    number[k]='\0';
  for( k=0;k<=63;k++)
    message[k]='\0';
}