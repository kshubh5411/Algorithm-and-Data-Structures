/**
  You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.
**/

Solution: In this we place the positive number in their segregate position:


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++){
	      cin>>a[i];
	  }
	  for(int i=0;i<n;i++){
	      while(a[i]>0&&a[i]<=n&&a[a[i]-1]!=a[i]){
	          swap(a[a[i]-1],a[i]);
	      }
	  }
	  int i=0;
	  for(i=0;i<n;i++){
	      if(i+1!=a[i])break;
	  }
	  cout<<i+1<<endl;
	  
	}
	return 0;
}
