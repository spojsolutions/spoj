#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define pb push_back
int tree[200009];
int hash[200009];
void update(int pos , int data){
	while(pos <= MAX){
		tree[pos]+= data;
		pos += (pos & (-pos));
	}
}
int read(int pos){
	int ans = 0;
	while(pos){
		ans += tree[pos];
		pos -= (pos & -pos);
	}
	return ans;
}
struct data{
	int pos , data , hash;
	char type;
};
bool cmp(const data &a , const data &b){
	return a.data == b.data ? a.pos < b.pos : a.data < b.data;
}
int b_search(int k){

	int low = 0 , high = 200000 , mid;
	while(low < high){
		mid = (low + high)>>1;
		if(read(mid) >= k)
			high = mid;
		else
			low = mid+1;
	}
	return low;
}
int save[200009];
data d[200009];
data query[200009];
int main(){
	int q ;
	scanf("%d",&q);
	for(int i = 0 ; i < q ; i++){
		scanf(" %c%d",&d[i].type , &d[i].data);
		d[i].pos = i+1;
	}

	sort(d , d + q , cmp);
	
	int cnt = 1 , prev = d[0].data;
	d[0].hash = cnt;
	save[cnt]= d[0].data;
	for(int i = 1 ; i < q ; i++)
	{
		if(prev != d[i].data){
			prev = d[i].data;
			cnt++;
			d[i].hash = cnt;
			save[cnt] = d[i].data;
		}
		else
			d[i].hash = cnt;
	}

	
	for(int i = 0 ; i < q ; i++){
		query[d[i].pos] = d[i];
	}
	// for(int i = 1 ; i <= q ; i++)
	// 	cout<<query[i].type <<" "<<query[i].data<<" " <<query[i].hash<<" "<<query[i].pos<<endl;
	cnt = 0;
	for(int i = 1 ; i <= q ; i++){
		if(query[i].type == 'I'){
			if(!hash[query[i].hash]){
				cnt++;
				hash[query[i].hash] = 1;
				update(query[i].hash , 1);
			}
		}
		else if(query[i].type == 'D'){

			if(hash[query[i].hash]){
				cnt--;
				hash[query[i].hash] = 0;
				update(query[i].hash , -1);
			}
		}

		else if(query[i].type == 'K'){
			if(query[i].data > cnt)
				printf("invalid\n");
			else
				printf("%d\n",save[b_search(query[i].data)]);
		}
		else
		{
			printf("%d\n",read(query[i].hash - 1));
		}
	}
	return 0;
}

