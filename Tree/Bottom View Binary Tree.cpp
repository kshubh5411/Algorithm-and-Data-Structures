/**
            1
         4     5
      2           3
      ans: 2 4 1 5 3
      
      Vertical Order Traversal of tree and find the leaf of each level
      
**/
void traverse(map<int,vector<int>>&mp,Node* root,int lvl){
    if(root==NULL)return;
    mp[lvl].push_back(root->data);
    traverse(mp,root->left,lvl-1);
    traverse(mp,root->right,lvl+1);
}
void bottomView(Node *root)
{
    if(root==NULL) return;
    //Level Order then find the lower one
    map<int,vector<int>>mp;
    int lvl=0;
    traverse(mp,root,lvl);
    vector<int>ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int>p=it->second;
        int s=p.size();
          ans.push_back(p[s-1]);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
   
}
