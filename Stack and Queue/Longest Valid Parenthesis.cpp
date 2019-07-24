/**
Longest valid Parentheses
Asked in:  
Google
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
**/

Solution With Stack
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cin>>s;
   stack<int>st;
   int n=s.length();
   int longest=0;
   for(int i=0;i<n;i++){
    if(s[i]=='(')st.push(i);
    else{
        if(!st.empty()&&s[st.top()]=='('){
            st.pop();}
        else st.push(i);
    }
   }
   if(st.empty())longest=n;
   else{
    int a=n,b;
    while(!st.empty()){
        b=st.top();
        st.pop();
        longest=max(longest,a-b-1);
        a=b;
    }
    longest=max(longest,a);
   }
   cout<<longest<<endl;
 }
