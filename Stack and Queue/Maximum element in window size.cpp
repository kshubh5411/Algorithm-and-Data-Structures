/**
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90
**/
/*
Solution: We make a deque and for first k element we simply put it inside the dequeue and if element is greater than deque back 
then we simply pop the deueu from back as it is irrelevant and add the element to the deque
for k to n element we simply check first if front value index in deque comes into range of (curr_index-k) if comes then simply 
remove from front else again we do same procedure to check the fill the deque 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n,w;
	  cin>>n>>w;
	  int a[n];
	  for(int i=0;i<n;i++){
	      cin>>a[i];
	  }
	  deque<int>dq;
	  
	  int i;
	  for( i=0;i<w;i++){
	      if(!dq.empty()&&a[i]>=a[dq.back()]){
	          while(!dq.empty()&&a[i]>=a[dq.back()]){
	              dq.pop_back();
	          }
	      }
	      dq.push_back(i);
	  }
	  cout<<a[dq.front()]<<" ";
	  for(int k=i;k<n;k++){
	      if((k-dq.front())>=w)dq.pop_front();
	      while(!dq.empty()&&a[k]>=a[dq.back()]){
	          dq.pop_back();
	      }
	      dq.push_back(k);
	      cout<<a[dq.front()]<<" ";
	  }
	  cout<<endl;
	}
	return 0;
}
