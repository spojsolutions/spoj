#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m, h;
	cin >> n >> m >> h;
	int ht[n][m];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			cin >> ht[i][j];
	
	int count = 0;
	for(int i = 0; i<n; i++){
		int low = 0;
		for(int j = 0; j<m; j++){
			if (ht[i][j] > low) low = max(low, ht[i][j]);
			else count++;
		}
	}

	cout << count << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/*
Penny is the emperor of town Pennyland. The city is full of tall buildings. But the problem is that the citizens of Pennyland are Clinomanic
(excessive desire to stay in bed) and are lazy, The king being the most lazy one. There is an Alien attack by Dukkar's army and he says,
"All men must die !". The city is a rectangular grid of size N x M. All the cells have buildings of height greater than zero. (They obviously don't
need roads). You are given the height of each building at cell.

Dukkar has a very high tech army. They have a gun that can produce a destruction wave that destroys anything that comes in its path. But he hates
math and didn't work hard on the wave, so when the wave touches a building, that part of wave gets absorbed and rest moves forward. 

Given the height of the wave H, which always comes from the left side, you need to find the number of buildings that remain perfectly intact.

Input:
First line contains number if test cases T. 
For each test case first line contains 3 integers N, M and H.
then N lines follow and each line contains M integers denoting the height of the building at that position;

Output:
Print the number of buildings that are perfectly intact.

Constraints:
0 < T <= 25
0 < N,M <= 1000
0 < H, height of each building <= 1000000000

Sample Input:
1
3 1 2 4
4 2 1 3
2 4 3 1
1 3 4 2

Sample Output:
8
*/