/**Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8
**/
void leftView(Node *root)
{
if(root==NULL) return;
  map<int,vector<int>>mp;
  queue<pair<int,Node*>>q;
  q.push(make_pair(0,root));
//   cout<<q.front().first->data<<endl;
  while(!q.empty()){
      pair<int,Node*>p=q.front();
      Node* r=p.second;
      int x=r->data;
      int l=p.first;
      q.pop();
      mp[l].push_back(x);
      if(r->left)
      q.push(make_pair(l+1,r->left));
      if(r->right)
      q.push(make_pair(l+1,r->right));
  }
  for(auto it=mp.begin();it!=mp.end();it++){
       cout<<it->second[0]<<" ";
    
  }
  
}
