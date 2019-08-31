/**
Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".
**/
Solution:
int Solution::solve(string A) {
    int n=A.length(),s=0;
    int e=n-1,r=e;
    while(s<e)
    {
        if(A[s]==A[e])
         {
             s++;
             e--;
         }
         else
         {
             s=0;
             r--;
             e=r;
         }
    }
    return(n-r-1);
}
