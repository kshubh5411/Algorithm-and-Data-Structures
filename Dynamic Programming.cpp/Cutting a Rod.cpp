/**
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
**/

#include<bits/stdc++.h>
using namespace std;
int cutRod(vector<int>&a,int n){
    int dp[n+1]={0};
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int maxi=INT_MIN;
        for(int j=0;j<i;j++){
            maxi=max(maxi,a[j]+dp[i-j-1]);

        }
        dp[i]=maxi;
    }
    return dp[n];
}
int main(){
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   int k=cutRod(a,n);
   cout<<k<<endl;
}
