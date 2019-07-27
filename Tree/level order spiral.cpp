/**
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
**/
Solution:
void zigzag(TreeNode* A,vector<vector<int> > &r,int f,int l,int i){
     if(A==NULL) return;
     if(l==1){
         r[i].push_back(A->val);
         return;
     }
     else{
         if(f){
                 zigzag(A->right,r,f,l-1,i);
                 zigzag(A->left,r,f,l-1,i);
         }
         else{
                
             zigzag(A->left,r,f,l-1,i);
             zigzag(A->right,r,f,l-1,i);
            }
     }
 }
 int height(TreeNode* root){
    if(root==NULL) return 0;
    return max(height(root->left)+1,height(root->right)+1);
 }
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
   
    int h=height(A);
    vector<vector<int> > r(h);
    int f=0;
    int q=0;
    for(int i=1;i<=h;i++){
        
        zigzag(A,r,f,i,q);
        q++;
        f=!f;
    }
    return r;
}
