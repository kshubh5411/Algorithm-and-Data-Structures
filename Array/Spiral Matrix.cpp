/**
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input: 
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7


**/

soln:


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>>A(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	        cin>>A[i][j];
	    }
	    int l=0,r=m-1,u=0,d=n-1;
	    while(l<=r&&u<=d){
	        for(int i=l;i<=r;i++)
	         cout<<A[u][i]<<" ";
	         u++;
	        for(int i=u;i<=d;i++)
	        cout<<A[i][r]<<" ";
	        r--;
	        if(u<=d){
	        for(int i=r;i>=l;i--)
	        cout<<A[d][i]<<" ";
	        }d--;
	        if(l<=r){
	        for(int i=d;i>=u;i--)
	        cout<<A[i][l]<<" ";
	        }l++;
	        
	    }
	    cout<<endl;
	}
	return 0;
}
