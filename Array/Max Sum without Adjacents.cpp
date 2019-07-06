/*Given an array A of positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, size of array. The second line of each test case contains N elements.

Output:
Print the maximum sum of a subsequence.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ci ≤ 107

Example:
Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13*/

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i]; }
	   int dp[n];
	   dp[0]=a[0];
	   dp[1]=max(a[0],a[1]);
	   for(int i=2;i<n;i++){
	       dp[i]=max(dp[i-1],a[i]+dp[i-2]);// take the current element or not
	   }
	   cout<<dp[n-1]<<endl;
	}
	return 0;
}
