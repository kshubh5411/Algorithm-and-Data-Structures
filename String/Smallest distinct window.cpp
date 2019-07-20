/**
 Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the length of the smallest such string.

Constraints:
1 <= T <= 100
1 <= |S| <= 105

Example:
Input:
2
aabcbcdbca
aaab

Output:
4
2
**/

Solution: Find Distinct count in string and traverse string from left and if if it appearing more than once free that
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int dist_count=0;
    set<char>st;

    for(int i=0;i<n;i++){
        if(st.find(s[i])==st.end()){dist_count++;}
        st.insert(s[i]);
    }

    int ch[256]={0};
    int c=0;
    int length=INT_MAX;
    int start=0,j;
    for(int i=0;i<n;i++){
        ch[s[i]]++;
        if(ch[s[i]]==1)c++;
        //cout<<"C="<<c<<endl;
        if(c==dist_count){
            while(start<n&&ch[s[start]]>1){
                ch[s[start]]--;
                start++;
            }
            //cout<<i<<" "<<start<<endl;
            if((i-start+1)<length){
                length=i-start+1;

            }
        }

    }
    //cout<<s.substr(start,length+1);
    cout<<length<<endl;
}
