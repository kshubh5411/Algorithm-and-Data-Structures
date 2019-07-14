/**Given an array A that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Input:
First line of input contain number of test cases T. First line of test case contain the size of array and second line of test case contain the array elements.

Output:
Output the maximum product of subarray.

Constraints:
1 <= T <= 100
1 <= N <= 104
-102 <= Ai <= 102

Example:
Input:
3
5
6 -3 -10 0 2
6
2 3 4 5 -1 0 
10
8 -2 -2 0 8 0 -6 -8 -6 -1

Output:
180
120
288**/

Solution:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    ll curr_max=a[0];
	    ll curr_min=a[0];
	    ll ans=a[0];
	    for(int i=1;i<n;i++){
	        int t=curr_min;
	        curr_min=min((ll)curr_max*a[i],min((ll)curr_min*a[i],a[i]));
	        curr_max=max((ll)curr_max*a[i],max((ll)t*a[i],a[i]));
	        ans=max(ans,curr_max);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
