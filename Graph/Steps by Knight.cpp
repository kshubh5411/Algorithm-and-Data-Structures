/**
   Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Constraints:
1<=T<=100
1<=N<=20
1<=knight_pos,targer_pos<=N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9
**/

SolN: Using BFS Graph:
#include<bits/stdc++.h>
using namespace std;
int knight(int n,int i,int j,int fi,int fj){
    int X[8]={-2,-2,-1,1,2,2,1,-1};
    int Y[8]={-1,1,2,2,1,-1,-2,-2};
    vector<vector<bool>>V(n,vector<bool>(n,false));
    queue<pair<pair<int,int>,int>>Q;
    Q.push({{i,j},0});
    V[i][j]=true;
    while(!Q.empty()){
        pair<pair<int,int>,int>P=Q.front();
        Q.pop();
        int x=P.first.first;
        int y=P.first.second;
        int d=P.second;
        
        if(x==fi&&y==fj)return d;
        for(int r=0;r<8;r++){
            int xi=x+X[r];
            int yj=y+Y[r];
            if(xi>=0&&yj>=0&&xi<n&&yj<n&&!V[xi][yj]){
                Q.push({{xi,yj},d+1});
                V[xi][yj]=true;
            }
        }
    }
    return 1;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i,j,fi,fj;
	    cin>>i>>j>>fi>>fj;
	    int ans=knight(n,i-1,j-1,fi-1,fj-1);
	    cout<<ans<<endl;
	}
	return 0;
}
