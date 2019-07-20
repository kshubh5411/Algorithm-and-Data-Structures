/**
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0
 
**/

Sol: fisrt Fill the first  row and column n now look to three side (i-1,j-1)(i-1,j)(i,j-1) and take min out of them because we are going to make a sqaure out of them + 1
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n,m;
	  cin>>n>>m;
	  int A[n][m];
	  for(int i=0;i<n;i++){
	      for(int j=0;j<m;j++){
	          cin>>A[i][j];
	      }
	  }
	  int B[n][m];
	  memset(B,0,sizeof(B));
	  int mx=INT_MIN;
	  for(int i=0;i<n;i++){
	      B[i][0]=A[i][0];
	      if(mx<B[i][0])mx=B[i][0];
	  }
	  for(int j=0;j<m;j++){
	      B[0][j]=A[0][j];
	       if(mx<B[0][j])mx=B[0][j];
	  }
	  for(int i=1;i<n;i++){
	      
	      for(int j=1;j<m;j++){
	       //   cout<<"Hell0"<<endl;
	          if(A[i][j]==1){
	              B[i][j]=min(B[i-1][j],min(B[i-1][j-1],B[i][j-1]))+1;
	           //   cout<<"B="<<B[i][j]<<endl;
	              if(B[i][j]>mx)mx=B[i][j];
	          }
	      }
	  }
	  cout<<mx<<endl;
	}
	return 0;
}
