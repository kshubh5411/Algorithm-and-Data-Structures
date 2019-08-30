/**
problem:
Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the number of Intervals and next line followed by the intervals starting and ending positions 'x' and 'y' respectively.


Output:

Print the intervals after overlapping in sorted manner.  There should be a newline at the end of output of every test case.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 100


Example:

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9
**/

Solution:
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.first<b.first;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	   int f,sc;
	  vector<pair<int,int>>a(n);
	  for(int i=0;i<n;i++){
	      int p,q;
	      cin>>p>>q;
	      a[i]={p,q};
	  }
	  sort(a.begin(),a.end(),comp);
	  stack<pair<int,int>>s;
	  s.push({a[0].first,a[0].second});
	  for(int i=1;i<n;i++){
	      int f=s.top().first;
	      int sc=s.top().second;
	   //   cout<<f<<" "<<sc<<endl;
	      if(sc>=a[i].first){
	          if(sc<=a[i].second)
	          sc=a[i].second;
	          s.pop();
	          s.push({f,sc});
	      }else{
	          s.push({a[i].first,a[i].second});
	      }
	  }
	  vector<int>ans;
	  int i=0;
	  while(!s.empty()){
	   //   cout<<s.top().first<<" "<<s.top().second<<" ";
	      ans.push_back(s.top().first);
	      
	      ans.push_back(s.top().second);
	     
	      s.pop();
	  }
	  sort(ans.begin(),ans.end());
	  for(auto it:ans){
	      cout<<it<<" ";
	  }
	  cout<<endl;
	}
	return 0;
}
