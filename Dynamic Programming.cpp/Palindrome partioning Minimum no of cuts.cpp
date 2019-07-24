/**
Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1
**/

Sol:
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cin>>s;
   int n=s.length();
   bool dp[n][n];
   memset(dp,false,sizeof dp);
   for(int i=0;i<n;i++){
    dp[i][i]=true;
   }
   for(int j=0;j<n-1;j++){
    if(s[j]==s[j+1]){
        dp[j][j+1]=true;
    }
   }
   for(int j=3;j<=n;j++){
      for(int i=0;i<=n-j;i++){
        if(s[i]==s[i+j-1]&&dp[i+1][i+j-2])dp[i][i+j-1]=true;
      }
   }
   // No of Partioning of Palindrome
   int cuts[n];
   memset(cuts,0,sizeof cuts);
   for(int i=0;i<n;i++){
    int temp=INT_MAX;
    if(dp[0][i]){
        cuts[i]=0;
    }else{
        for(int j=0;j<i;j++)
        if(dp[j+1][i]&&temp>cuts[j]+1){
         temp=cuts[j]+1;
         cuts[i]=temp;
       }
    }

   }
    cout<<"Minimum Number Of Cuts is/are="<<cuts[n-1]<<endl;

}
