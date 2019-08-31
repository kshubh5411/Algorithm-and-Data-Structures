/**
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
**/
Sol:
int maxlen=0,s=0,e=0;
void checkpalin(string A,int l,int r)
{
    while((l>=0&&r<A.length())&&(A[l]==A[r]))
    {
        if(r-l+1>maxlen)
        {
            s=l;
            e=r+1;
            maxlen=r-l+1;
        }
        l--;
        r++;
        //cout<<"A"<<endl;
    }
}
string Solution::longestPalindrome(string A) {
    int n=A.length();
    for(int i=0;i<n;i++)
    {
        checkpalin(A,i,i);
        checkpalin(A,i,i+1);
    }
   //cout<<s<<" "<<e-1<<endl;
    //int l=-e-s+1;
    string B="";
    for(int i=s;i<e;i++)
     B+=A[i];
    return B;
}

