/**
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1
**/

Solution:
#include<bits/stdc++.h>
using namespace std;

int Edit(string s,string d,int n,int m,vector<vector<int>>&dp){
    if(n==0) return m;
    if(m==0) return n;
    if(dp[n][m]>-1){
        return dp[n][m];
    }
    if(s[n-1]==d[m-1]){
        dp[n][m]=Edit(s,d,n-1,m-1,dp);
    }
    else{
        dp[n][m]=1+min(Edit(s,d,n,m-1,dp),min(Edit(s,d,n-1,m-1,dp),Edit(s,d,n-1,m,dp)));
    }
    return dp[n][m];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n,m;
	  cin>>n>>m;
	  string s;
	  string d;
	  cin>>s>>d;
	  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	  int ans=Edit(s,d,n,m,dp);
	  cout<<ans<<endl;
	}
	return 0;
}
