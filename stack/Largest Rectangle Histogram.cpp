/**Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
**/
/** 
Approach: If stack is empty fill the array element
          if(a[i] is greater or equal than stack top value then simply push the element
          else 
             we have to pop out the stack until we get the smaller element in stack 
             if stack is empty area= h*i;
             else
             height=max(height,h*(i-s.top()-1);
             
   **/
   #include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  ll n;
	  cin>>n;
	  ll a[n];
	  for(int i=0;i<n;i++)
	  cin>>a[i];
	  stack<ll>s;
	  ll mx=INT_MIN;
	  ll i;
	  for( i=0;i<n;i++){
	      if(s.empty()||a[i]>=a[s.top()]){
	          s.push(i);
	      }else{
	          while(!s.empty()&&a[i]<a[s.top()]){
	              int h=a[s.top()];
	              s.pop();
	              if(s.empty()){
	                  mx=max(mx,h*i);
	              }else{
	                  mx=max(mx,h*((i-s.top())-1));
	              }
	          }
	          s.push(i);
	      }
	  }
	  while(!s.empty()){
	      int h=a[s.top()];
	      s.pop();
	      if(s.empty()){
	          mx=max(mx,h*i);
	      }else{
	          mx=max(mx,h*(i-s.top()-1));
	      }
	  }
	  cout<<mx<<endl;
	}
	return 0;
}
