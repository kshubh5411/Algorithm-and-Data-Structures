/**Count ways to reach a score using 1 and 2 with no consecutive 2s
A cricket player has to score N runs, with condition he can take either 1 or 2 runs only and consecutive runs should not be 2. Find all the possible combination he can take.
**/
#include <bits/stdc++.h>
using namespace std;
int recur(int n,vector<vector<int>>&dp,int flag){
    
    if(n==0) return 1;
    if(dp[n][flag]>-1)return dp[n][flag];
    int sum=0;
    if(flag==0&&n>1){
        sum+=recur(n-1,dp,0)+recur(n-2,dp,1);
    }else{
        sum+=recur(n-1,dp,0);
        
    }
    dp[n][flag]=sum;
    return dp[n][flag];
}

int main() {
	int n;
	cin>>n;
	
	
	vector<vector<int>>dp(n+1,vector<int>(2,-1));
	int flag=0;
	int step=recur(n,dp,flag);
	cout<<step<<endl;
	return 0;
}
