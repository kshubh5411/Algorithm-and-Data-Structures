#include<bits/stdc++.h>
using namespace std;
void permute(string s,int n,int l){
    if(l==n-1){
        cout<<s<<" ";
        return;
    }
    for(int i=l;i<n;i++){
        swap(s[i],s[l]);
        sort(s.begin()+l+1,s.end());
        permute(s,n,l+1);
        sort(s.begin()+l+1,s.end());
        swap(s[i],s[l]);
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end());
	    int n=s.length();
	    permute(s,n,0);
	    cout<<endl;
	}
	return 0;
}
