/**
  Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

Example



​For the above board output will be 3 
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

Output:
3
1

Explanation:
Testcase 1: 
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
**/
Solution With Graph and DFS :


#include<bits/stdc++.h>
using namespace std;
int minimumThrow(vector<int>&a){
    queue<pair<int,int>>q;
    q.push({1,0});
    while(!q.empty()){
        pair<int,int>p=q.front();
        q.pop();
        int x=p.first;
        int t=p.second;
        if(x==30) return t;
        for(int i=x+1;i<=30&&i<=x+6;i++){
            if(a[i]==-1){
                q.push({i,t+1});
            }else{
                q.push({a[i],t+1});
            }
            
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
	    vector<int>a(31,-1);
	    //Make A array of size 30 start from 1===
	    for(int i=0;i<n;i++){
	        int x,y;
	        cin>>x>>y;
	        a[x]=y;
	    }
	    cout<<minimumThrow(a)<<endl;
	}
	return 0;
}



