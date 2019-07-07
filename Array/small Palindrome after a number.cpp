/** 
 for even case:
if A[mid-1]<A[mid]: A[mid-1]=A[mid-1]+1;
if(A[mid-1]>A[mid]: A[mid]=A[mid-1];


for odd:
if(A[mid-1]>A[mid+1]: A[mid+1]=A[mid-1];
if(A[mid-1]<A[mid+1]: now check for middle:
 check upto index if(A[mid]==9)
  A[mid-1]=A[mid-1]+1;
 else
    A[mid]=A[mid]+1;

for all digit 9
  simply add n-1 between two 1s
  eg:
  9 9 9 
  1 0 0 1
  
  
  in Cpp:
  **/
  
  
  #include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[n],f=0;
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	        if(A[i]!=9)f=1;
	    }
	    int m;
	    int i,j;
	    if(f==0){
	        A[0]=1;
	        A[n]=1;
	        for(int i=1;i<n;i++)A[i]=0;
	        
	    }
	    else if(n&1){
	        m=n/2;
	        if(A[m-1]>A[m+1]){
	            A[m+1]=A[m-1];
	            i=m-2;
	            j=m+2;
	        }else if(A[m-1]<A[m+1]){
	            if(A[m]==9){
	                A[m-1]=A[m-1]+1;
	                A[m]=0;
	                
	            }else{
	                A[m]=A[m]+1;
	            }
	            i=m-1;
	            j=m+1;
	            
	        }
	        else{
	       
	            int p=m-1;int q=m+1;
	            int f1=0;
	            while(p>=0&&q<n&&A[p]==A[q]){
	                if(A[p]!=9||A[q]!=9)f1=1;
	                p--;q++;
	            }
	            if(f1==0&&p>=0&&q<n){
	                //cout<<"UHH1"<<endl;
	               A[p]=A[p]+1;
	               A[q]=A[p];
	               for(int r=p+1;r<q;r++)A[r]=0;
	               i=p;j=q;
	            }
	           else if(p>=0&&q<n){
	              
	                if(A[p]>A[q]){
	                    
	                    A[q]=A[p];
	                    i=p-1;
	                    j=q+1;
	                }else if(A[p]<A[q]){
	                    
	                    if(A[m]==9){
	                     A[m-1]=A[m-1]+1;
	                     A[m]=0;
	                
	                       }else{
        	             A[m]=A[m]+1;
        	             }
        	            i=m-1;
        	            j=m+1;
	                }
	            }
	            
	        }
	        while(i>=0&&j<n){
	            A[j]=A[i];
	            i--;j++;
	        }
	       
	        
	    }else{
	        
	        int m1=n/2;
	        int m2=n/2-1;
	        if(A[m1]>A[m2]){
	            A[m2]=A[m1];
	            i=m1-1;
	            j=m2+1;
	        }else if(A[m1]<A[m2]){
	            A[m1]=A[m1]+1;
	            A[m2]=A[m1];
	            i=m1-1;
	            j=m1+1;
	        }else{
	            while(m1>=0&&m2<n&&A[m1]==A[m2]){
	                m1--;m2++;
	            }
	            if(m1>=0&&m2<n&&A[m1]>A[m2]){
	            A[m2]=A[m1];
	            i=m1-1;
	            j=m2+1;
	        }else if(m1>=0&&m2<n&&A[m1]<A[m2]){
	            A[m1]=A[m1]+1;
	            A[m2]=A[m1];
	            i=m1-1;
	            j=m1+1;
	        }
	        }
	        
	        
	    }if(f==0)
	    for(int i=0;i<=n;i++)cout<<A[i]<<" ";
	    else{
	        for(int i=0;i<n;i++)cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
