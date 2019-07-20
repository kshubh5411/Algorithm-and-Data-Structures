#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char S[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>S[i][j];
    }
    bool V[n][m];
    int r,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(S[i][j]=='0')
              V[i][j]=true;
              else
              V[i][j]=false;
              if(S[i][j]=='s')r=i,c=j;
        }
    }
    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},0});
    V[r][c]=true;
    int f=0;
    int d;
    while(!q.empty()){
        pair<pair<int,int>,int>P=q.front();
        q.pop();
        int x=P.first.first;
        int y=P.first.second;
         d=P.second;
        if(S[x][y]=='d'){
            f=1;
            break;
        }
        for(int i=0;i<=3;i++){
            int x1=x+X[i];
            int y1=y+Y[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m&&!V[x1][y1])
                {
                    V[x1][y1]=true;
                    q.push({{x1,y1},d+1});
                }
        }

    }
    if(f)cout<<d<<endl;
    else cout<<"-1"<<endl;
}
