/**
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Input Format

The only argument given is integer array A.
Output Format

Return the total water it is able to trap after raining..
For Example

Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1: <img src="http://i.imgur.com/0qkUFco.png">
    
    In this case, 6 units of rain water (blue section) are being trapped.
**/
Solution: Find left highest and right highest and if lh < rh then check whether the current length is lower if lower simply add the diff
to the result if grater make low highest to current element, similarly if left highest greater than right highest do same

int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int l=0,r=n-1;
    int lh=A[0],rh=A[n-1];
    int ans=0;
    while(l<=r)
    {
        if(lh<rh)
        {
            if(l==0)
              lh=A[0];  
            else if(lh<=A[l])
              lh=A[l];
            else 
              ans+=(lh-A[l]);
              l++;
        }
        else
        {
            if(r==n-1)
              rh=A[n-1];
            else if(rh<=A[r])
              rh=A[r];
            else 
              ans+=(rh-A[r]);
              r--;
        }
       
    }
    return ans;
}
