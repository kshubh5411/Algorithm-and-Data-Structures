/**
Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

The output should contain only unique quadrples  For example, if input array is {1, 1, 1, 1, 1, 1} and K = 4, then output should be only one quadrple {1, 1, 1, 1}
 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains two integers N and K. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K. Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100

Example:
Input:
2
5 3
0 0 2 1 1 
7 23
10 2 3 4 5 7 8

Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

 **/
 //Solution:Sort the element Divide the problem into 3sum, 2sum. also take care to remove the repeated integer.
 //Complexity: n^3.
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
	    for(int i=0;i<n;i++)cin>>a[i];
	    set<vector<int>> res;
	    vector<int>ans;
	    int f=0;
	    sort(a,a+n);
	    for(int i=0;i<n-3;i++){//3 sum
	        if(i!=0&&a[i]==a[i-1])continue;// repeat element 
	        for(int j=i+1;j<n-2;j++){// 2 sum
	            if(j!=i+1&&a[j]==a[j-1])continue;// repeat element
	            int x=tar-a[i]-a[j];
	            int l=j+1,r=n-1;
	            while(l<r){      // using two pointers we find next two elements
	                
	                if((a[l]+a[r])>x){
	                    r--;
	                }else if((a[l]+a[r])<x){
	                    l++;
	                }else{
	                    f=1;
	                   // cout<<"AA"<<endl;
	                    ans={a[i],a[j],a[l],a[r]};
	                    res.insert(ans);
	                    l++;r--;
	                   
	                }
	            }
	        }
	    }
	    if(f==0){cout<<"-1";}else{
	        for(auto it=res.begin();it!=res.end();it++){
	           const std:: vector<int>& v=(*it);
	            for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	            cout<<"$";
	        }
	   }
	    cout<<endl;
	}
	return 0;
}
