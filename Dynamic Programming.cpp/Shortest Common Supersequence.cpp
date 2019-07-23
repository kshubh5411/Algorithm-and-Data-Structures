/**
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case contains two space separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
**/
Sol: find longest common subsequence and substract the length of both string with common subsequnce
#include<bits/stdc++.h>
using namespace std;
int lcs(string s,string d,int n,int m,vector<vector<int>>&dp){
    if(n==0||m==0)return 0;
    if(dp[n][m]>-1)return dp[n][m];
    if(s[n-1]==d[m-1]){
        dp[n][m]=1+lcs(s,d,n-1,m-1,dp);
    }else{
        dp[n][m]=max(lcs(s,d,n-1,m,dp),lcs(s,d,n,m-1,dp));
    }
    return dp[n][m];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  string s,d;
	  cin>>s>>d;
	  int n=s.length();
	  int m=d.length();
	  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	  int k=lcs(s,d,n,m,dp);
	  cout<<(n+m-k)<<endl;
	}
	return 0;
}
