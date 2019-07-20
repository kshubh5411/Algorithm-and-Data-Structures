/**
  Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.
Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107
Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2
Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.
**/

/*Solution: 
  we move in the step  range and find the max reach  and if step==0 we change the ladder, finally on reaching last we update the
  count value*/
  
  
  #include<bits/stdc++.h>
using namespace std;
int jumpArray(vector<int>&A,int n){
    
    int cnt=1;
    int step=A[0];
    int maxjump=0;
    if(step==0) return -1;
    for(int i=1;i<n;i++){
        
        if(i>=n-1) return cnt;
        maxjump=max(maxjump,i+A[i]);
        step--;
        if(step==0) //Change the ladder as no step 
        {
            cnt++;
            if(i>=maxjump)// No jump happen i.e 0 occur not able to cross the boundary too
             return -1;
            step=maxjump-i;
        }
    }
    return -1;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>A(n,0);
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    int jump=jumpArray(A,n);
	    cout<<jump<<endl;
	}
	return 0;
}
