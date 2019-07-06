#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)cin>>a[i];
 int k;cin>>k;
 unordered_map<int,int>mp;
 mp.insert(make_pair(0,1));
 int prev_sum=0,c=0;
 for(int i=0;i<n;i++){
     prev_sum+=a[i];
     if(mp.find(prev_sum-k)!=mp.end()){
       c+=mp[prev_sum-k];
     }
     mp[prev_sum]++;
 }
 cout<<c<<endl;
}
