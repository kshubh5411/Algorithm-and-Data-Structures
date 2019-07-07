/**
Given a directed graph, you need to complete the function topoSort which returns an array having the topologically sorted elements of the array and takes two arguments. The first argument is the Graph graph represented as adjacency list and the second is the number of vertices N.

Note : There can be multiple topological sorts of a Graph.  The driver program that calls your function doesn't match your output element by element, but checks whether the output produced by your function is a valid topological sort or not.

Input:
The first line of input takes the number of test cases then T test cases follow . Each test case contains two lines. The first  line of each test case  contains two integers E and N representing no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0 .

Constraints:
1 <= T <= 50
1 <= E, N <= 50
0 <= u, v

Example:
Input
2
6 6 
5 0 5 2 2 3 4 0 4 1 1 3
4 4
3 0 1 0 2 0 0 1

Output:
1
0
**/

//Solution: Using Dfs store the value in stack but always put the current visited last;

void dfs(vector<int> adj[],int n,int i,vector<bool>&v,stack<int>&s){
    //  cout<<"A"<<endl;
      v[i]=true;
      
      for(auto it=adj[i].begin();it!=adj[i].end();it++){
          if(!v[*it]){
              dfs(adj,n,*it,v,s);
          }
      }
      s.push(i);
}
int* topoSort(int V, vector<int> adj[])
{
    int *a= new int[V];
    stack<int>s;
    vector<bool>v(V,false);
    
    for(int i=0;i<V;i++){
        if(!v[i]){
           dfs(adj,V,i,v,s);
        }
    }
    int i=0;
    while(!s.empty()){
        a[i]=s.top();
        s.pop();
        i++;
    }
   
    return a;
    
}
