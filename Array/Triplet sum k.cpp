#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,tar;
	    cin>>n>>tar;
	    int a[n];
	   
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        
	    }
	    
	    int f=0;
	    for(int i=0;i<n;i++){
	        set<int> s;
	        for(int j=i+1;j<n;j++){
	            int x=tar-(a[i]+a[j]);
	            if(s.find(x)!=s.end()){
	               f=1;
	               cout<<"1"<<endl;
	               break;
	            }
	            s.insert(a[j]);
	        }
	        if(f)break;
	    }
	    if(!f)cout<<"0"<<endl;
	}
	return 0;
}
