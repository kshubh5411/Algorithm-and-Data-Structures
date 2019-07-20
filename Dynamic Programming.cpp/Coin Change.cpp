#include<iostream>
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
	  for(int i=0;i<n;i++)cin>>a[i];
	  int k;
	  cin>>k;
	  int dp[k+1]={0};
	  
      dp[0]=1;
      for( int i=0;i<n;i++){
          for(int j=a[i];j<=k;j++){
              dp[j]+=dp[j-a[i]];
          }}
      cout<<dp[k]<<endl;
	}
	return 0;
}
