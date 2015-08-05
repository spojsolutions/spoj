//compatible with arduino compiler
#include <SoftwareSerial.h>
SoftwareSerial gprsSerial(2, 3);
int Gpsdata;             // for incoming serial data 
  unsigned int finish =0;  // indicate end of message
  unsigned int pos_cnt=0;  // position counter
  unsigned int flg    =0;  // GPS flag 
  unsigned int com_cnt=0;  // comma counter
  String lati="0";            // latitude array
  String lg="0";             // longitude array
  String tm="0";             // time array
  String save_lati , save_lg,save_spd;
  char validity;        // validity of data
  char dir1 , dir2;         // direction N/E
  String datei ="0";           // date array
  String spd ="0";
  char temp;
  int long long count = 1;
void setup()
{
  gprsSerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Config SIM900...");
  delay(2000);
  Serial.println("Done!...");
  gprsSerial.flush();
  Serial.flush();

  // attach or detach from GPRS service 
  gprsSerial.println("AT+CGATT?");
  delay(100);
  toSerial();


  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
  delay(2000);
  toSerial();

  // bearer settings
  gprsSerial.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();
}


void loop()
{
   // initialize http service
   if(count%10 == 0){
     count= 0 ;
     gprsSerial.flush();
      Serial.flush();
      gprsSerial.println("AT+CIPSHUT");
      delay(100);
      toSerial();
      gprsSerial.println("AT+CGATT?");
      delay(100);
      toSerial();
    
      // attach or detach from GPRS service 
      gprsSerial.println("AT+CGATT=1");
      delay(100);
      toSerial();
    
    
      // bearer settings
      gprsSerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
      delay(2000);
      toSerial();
    
      // bearer settings
      gprsSerial.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
      delay(2000);
      toSerial();
    
      // bearer settings
      gprsSerial.println("AT+SAPBR=1,1");
      delay(2000);
      toSerial();
   }
   count++;
   Receive_GPS_Data();
   gprsSerial.println("AT+HTTPINIT");
   delay(2000); 
   toSerial();

   // set http param value
   gprsSerial.println("AT+HTTPPARA=\"URL\",\"http://shuttletracker.hostei.com/?lat="+save_lati+"&long="+save_lg+"&speed="+save_spd+"\"");
   delay(2000);
   toSerial();

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   gprsSerial.println("AT+HTTPACTION=0");
   delay(6000);
   toSerial();

   // read server response
   gprsSerial.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   gprsSerial.println("");
   gprsSerial.println("AT+HTTPTERM");
   toSerial();
   delay(300);

   gprsSerial.println("");
   delay(30000);
   finish=0;pos_cnt = 0;
}

void toSerial()
{
  while(gprsSerial.available()!=0)
  {
    Serial.write(gprsSerial.read());
  }
}
  void Receive_GPS_Data()
  {
    while(finish==0){
      while(Serial.available()>0){         // Check GPS data 
        Gpsdata = Serial.read();
        temp = (char)Gpsdata;
        //Serial.print(temp);
        flg = 1;
       if( temp=='$' && pos_cnt == 0)   // finding GPRMC header
         pos_cnt=1;
       if( temp=='G' && pos_cnt == 1)
         pos_cnt=2;
       if( temp=='P' && pos_cnt == 2)
         pos_cnt=3;
       if( temp=='R' && pos_cnt == 3)
         pos_cnt=4;
       if( temp=='M' && pos_cnt == 4)
         pos_cnt=5;
       if( temp=='C' && pos_cnt==5 )
         pos_cnt=6;
       if(pos_cnt==6 &&  temp ==','){   // count commas in message 
         com_cnt++;
         flg=0;
       } 
       if(com_cnt == 1 && flg == 1){
          tm += temp;
          flg = 0;
       }
       if(com_cnt == 2 && flg == 1){
          validity = temp;
          flg = 0;
       }
       if(com_cnt==3 && flg==1){
        lati+=  temp;         // latitude
        flg=0;
       }
       if(com_cnt == 4 && flg == 1){
          dir1 = temp;
          flg = 0;
       }
       if(com_cnt==5 && flg==1){
         lg+=  temp;         // Longitude 
         flg=0;
       }
       if(com_cnt == 6 && flg == 1){
          dir2 = temp;
          flg = 0;
       }
       if(com_cnt == 7 && flg == 1){
         spd+= temp;
         flg = 0;
       }
       if(com_cnt == 9 && flg == 1){
          datei+= temp;
          flg=0;
       }
       if( temp == '*' && com_cnt >= 5){
         save_lati = lati;
         save_spd = spd;
         save_lg = lg;
         lati.remove(0);
         tm.remove(0);
         lg.remove(0);
         spd.remove(0);
         datei.remove(0);
         com_cnt = 0;
         flg     = 0;
         finish  = 1;
         validity = 'L';
          dir2 = 'A';
          dir1 = 'A';
      }
    } 
 }
}
