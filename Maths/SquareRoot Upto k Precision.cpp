#include<bits/stdc++.h>
using namespace std;
float squareRoot(int  n ,int k){
     float ans=1;
     int l=0,h=n;
     while(l<=h){

          int mid=(l+h)/2;
          if(mid*mid==n){
              ans=mid;
              break;
          }
          else if (mid*mid<n){
              ans=mid;
              l=mid+1;
          }
          else{
              h=mid-1;
          }
     }
    // cout<<ans<<endl;
     float inc=0.1;  // For upto K Precision
     for(int i=0;i<k;i++){

         while((ans*ans)<=n){
         //cout<<"A"<<endl;
             ans+=inc;
         }
         ans-=inc;
         inc=inc/10;
     }
     return ans;

}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	   int n,prec;// upto k precision
	   cin>>n>>prec;
	   float ans=squareRoot(n,prec);
	   cout<<ans<<endl;

	}
	return 0;
}
