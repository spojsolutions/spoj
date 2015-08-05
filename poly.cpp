#include <bits/stdc++.h>
using namespace std;
int get_parent(int arr[] , int id){
	int temp = id;
	while(arr[temp] != -1){
		temp = arr[temp];
	}
	//arr[id] = (temp==id?-1: temp);
	return temp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n , g;
		cin>>n>>g;
		int alligence[g+9];
		int arr[200000];
		memset(arr , -1 , sizeof arr);
		for(int i = 1 ; i <= g ; i++)
			cin>>alligence[i];
		int q;
		cin>>q;
		while(q--){
			int type ;
			cin>>type;
			if(type==1){
				int id1 , id2;
				char c;
				cin>>c>>id1>>id2;
				if(c == 'c'){
					//int par = get_parent(arr , 50000 + id1);
					arr[id2+50000] = 50000 + id1;
				}
				else if(c=='g'){
					arr[id2+50000] = id1;
				}
			}
			else if(type == 2){
				int id;
				cin>>id;
				int temp = get_parent(arr , 50000 + id);
				if(temp == id+50000)
					cout<<"Free\n";
				else if(alligence[temp] ==1 )
					cout<<"Dukkar\n";
				else
					cout<<"Bhagat\n";

			}
			else if(type == 3){
				int id;
				cin>>id ;
				alligence[id] ^= 1;
			}
		}
	}
	return 0;
}