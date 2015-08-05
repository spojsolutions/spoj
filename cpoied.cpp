/*
Tested at:
http://www.spoj.pl/problems/SUBLEX/
If all distinct substrings of string S were sorted lexicographically, which one will be the K-th smallest?

Thanks to this discussions 
http://stackoverflow.com/a/9390461/1348550
*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define MAX 90099
using namespace std;
char str[MAX]; //input
int Rank[MAX], suffixArray[MAX]; //output
int cnt[MAX], Next[MAX]; //internal
bool bh[MAX], b2h[MAX];
int Height[MAX];
int AccumulatedCount[MAX];

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b)
{
	return str[a] < str[b];
}
void print(int index)
{
	for(int i=index;i<strlen(str);++i)
	{
		cout<<str[i];
	}
	cout<<endl;
}

void suffixSort(int n){
	//sort suffixes according to their first characters
	for (int i=0; i<n; ++i){
		suffixArray[i] = i;
	}
	sort(suffixArray, suffixArray + n, smaller_first_char);
	//{suffixArray contains the list of suffixes sorted by their first character}

	for (int i=0; i<n; ++i){
		bh[i] = i == 0 || str[suffixArray[i]] != str[suffixArray[i-1]];
		b2h[i] = false;
	}

	for (int h = 1; h < n; h <<= 1){
		//{bh[i] == false if the first h characters of suffixArray[i-1] == the first h characters of suffixArray[i]}
		int buckets = 0;
		for (int i=0, j; i < n; i = j){
			j = i + 1;
			while (j < n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
		}
		if (buckets == n) break; // We are done! Lucky bastards!
		//{suffixes are separted in buckets containing strings starting with the same h characters}

		for (int i = 0; i < n; i = Next[i]){
			cnt[i] = 0;
			for (int j = i; j < Next[i]; ++j){
				Rank[suffixArray[j]] = i;
			}
		}

		cnt[Rank[n - h]]++;
		b2h[Rank[n - h]] = true;
		for (int i = 0; i < n; i = Next[i]){
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;
				if (s >= 0){
					int head = Rank[s];
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
				}
			}
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;
				if (s >= 0 && b2h[Rank[s]]){
					for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i=0; i<n; ++i){
			suffixArray[Rank[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i=0; i<n; ++i)
	{
		Rank[suffixArray[i]] = i;
	}
}
// End of suffix array algorithm



void getHeight(int n)
{
	for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
	Height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (Rank[i] > 0)
		{
			int j = suffixArray[Rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			Height[Rank[i]] = h;
			if (h > 0) h--;
		}
	}
}
// End of longest common prefixes algorithm
int main()
{
	int kth,T, diff,suffixsize;
	gets(str);
	int Len=strlen(str);
	scanf("%d",&T);
	suffixSort(Len);
	getHeight(Len);

	/*******************************FIND THE KTH LEXOGRAPHIC SUBSTR STARTS HERE ***********/
	int sum=0;
	for(int i=0;i<Len;++i)
	{
		suffixsize=(Len-suffixArray[i]);
		diff=suffixsize-Height[i];					/*Note that the diff is the total distinct substrings that a suffix i will  give*/
		sum=sum+diff;
		AccumulatedCount[i]=sum;
	}

	/*So Till Here I have cached accumulated count also.*/
	while(T--)
	{
		scanf("%d",&kth);						//Kth Lexographic Substring

		//Step 1:  find the first entry that has an accumulated count greater than or equal to K
		int FirstEntry=0;
		for(int i=0;i<Len;++i)
		{
			if(AccumulatedCount[i]>=kth)
			{
				FirstEntry=i;
				break;
			}
		}
		cout<<FirstEntry<<endl;
		//Then remove the prefix it shares with the previous entry.This is equivalent to LCP[i].
		int sharedprefixLength=Height[FirstEntry];
		cout<<sharedprefixLength<<endl;
		/*So the Answer is the common prefix + Total (Kth-accumulated [entry-1]) character(after common prefiexes ) from FirstEntry suffix*/

		//Lets print the COMMON prefix First
		int Idx,j;
		for(Idx=suffixArray[FirstEntry],j=0;j<sharedprefixLength;++j,++Idx)
			putc(str[Idx],stdout);
		cout<<Idx<<endl;
		// Then print the Total (Kth-accumulated [entry-1]) characters from the position after where the common prefix Ends in the Suffix [Entry]

		//Note Idx is at the position just after the common prefix string in the suffix[First Entry].
		//so just print (Kth-accumulated [entry-1]) characters from this position.
		cout<<AccumulatedCount[FirstEntry-1]<<endl;
		for(int j=0;j<kth-AccumulatedCount[FirstEntry-1];++j,++Idx)
			putc(str[Idx],stdout);

		putc('\n',stdout);
	}
	return 0;
}