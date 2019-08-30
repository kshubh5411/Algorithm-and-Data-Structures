/**
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
**/

Solution:
move from right to left if left element is smaller than left-1 then continue
else swap with left element to its next greater number and reverse from current index+1 to last

void swap(int *a,int *b) 
{ 
    if( *a == *b ) 
        return; 
    *a^=*b; 
    *b^=*a; 
    *a^=*b; 
} 
void rev(vector<int >&s,int l,int r) 
{ 
    while(l<r) 
        swap(&s[l++],&s[r--]); 
} 
int bsearch (vector<int >&s,int l,int r,int key) 
{ 
    int index = -1; 
    while(l<=r) 
    { 
        int mid = l+(r-l)/2; 
        if(s[mid]<=key) 
            r=mid-1; 
        else
        { 
            l=mid+1; 
            if(index = -1 || s[index]<=s[mid]) 
                index = mid; 
        } 
    } 
return index; 
} 
bool nextpermutation(vector<int >&s) 
{ 
    int len = s.size(), i=len-2; 
    while(i>=0 && s[i]>=s[i+1]) 
    --i; 
    if(i<0) 
        return false; 
    else
    { 
        int index=bsearch(s,i+1,len-1,s[i]); 
        swap(&s[i],&s[index]); 
        rev(s,i+1,len-1); 
        return true; 
    } 
} 


void Solution::nextPermutation(vector<int> &A) {
   
    int n=A.size();
    if(n==1)
    {
        return;
    }
    bool val = nextpermutation(A); 
    if (val == false) 
        { sort(A.begin(),A.end());
          return;
        }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}




