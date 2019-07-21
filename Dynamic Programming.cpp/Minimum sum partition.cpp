/**
 Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11
**/

Solution Either take the value or not and at last check the abs value of stotal-curr_sum
#include<bits/stdc++.h>
using namespace std;
int findSubset(int *a,int n,vector<vector<int>>&dp,int stotal,int curr_sum){
    if(n==0){
        dp[n][curr_sum]=abs((stotal-curr_sum)-curr_sum);
        return dp[n][curr_sum];
    }
    if(dp[n][curr_sum]>-1)return dp[n][curr_sum];
    
    dp[n][curr_sum]=min(findSubset(a,n-1,dp,stotal,curr_sum+a[n-1]),findSubset(a,n-1,dp,stotal,curr_sum));
    return dp[n][curr_sum];
    
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  int a[n];
	  int stotal=0;
	  for(int i=0;i<n;i++){cin>>a[i];stotal+=a[i];}
	  vector<vector<int>>dp(n+1,vector<int>(stotal+1,-1));
	  int curr_sum=0;
	  int ans=findSubset(a,n,dp,stotal,curr_sum);
	  cout<<ans<<endl;
	}
	return 0;
}
