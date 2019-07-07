/**
A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present. The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findIslands().

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[i][j] <= 1

Example(To be used only for expected output) :
Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output
2
2

Explanation:
Testcase 1: The graph will look like
1 1 0
0 0 1
1 0 1
Here, two islands will be formed
First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][2]}
Second island will be formed by {A[2][0]}.


**/

Solution With DFS

void dfs(vector<vector<bool>>&v,vector<int> A[],int n,int m,int i,int j){
    
    int X[8]={1,1,1,-1,-1,-1,0,0};
    int Y[8]={0,1,-1,0,1,-1,1,-1};
    v[i][j]=true;
    for(int p=0;p<8;p++){
        int x=i+X[p];
        int y=j+Y[p];
        if(x>=0&&y>=0&&x<n&&y<m&&!v[x][y]&&!A[x][y]==0){
            dfs(v,A,n,m,x,y);
        }
    }
}
int findIslands(vector<int> A[], int N, int M)
{
    vector<vector<bool>>v(N,vector<bool>(M,false));
    int c=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!v[i][j]&&!A[i][j]==0){
                c+=1;
               dfs(v,A,N,M,i,j); 
            }
        }
    }
    return c;
    
    
}
