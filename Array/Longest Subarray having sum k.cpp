#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n,k;
	  
	  cin>>n>>k;
	  int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   unordered_map<int,int> mp;
   int  curr_sum=0;
   int l=0;
  
   for(int i=0;i<n;i++){
    curr_sum+=a[i];
    if(curr_sum==k){
        l=max(l,i+1);
    }
    if(mp.find(curr_sum-k)!=mp.end())
    {
        l=max(l,i-mp[curr_sum-k]);

    }
   // cout<<"L="<<l<<endl;
    if(mp.find(curr_sum)==mp.end())
    mp[curr_sum]=i;
   }
    cout<<l<<endl;
	}
	return 0;
}
