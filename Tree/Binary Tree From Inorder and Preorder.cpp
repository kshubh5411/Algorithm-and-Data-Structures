/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* construct(vector<int> &A, vector<int> &B,int f,int s,int n){
     if(f>s)return NULL;
     TreeNode* node=new TreeNode(A[n]);
     int id;
     for(int i=f;i<=s;i++){
         if(A[n]==B[i]){
             id=i;
             break;
         }
     }
     node->right=construct(A,B,id+1,s,n+id-f+1);
     
     node->left=construct(A,B,f,id-1,n+1);
     return node;
 }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n=A.size();
    TreeNode* head=construct(A,B,0,n-1,0);
}
