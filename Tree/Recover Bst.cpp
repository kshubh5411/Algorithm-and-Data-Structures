/**
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          
**/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void inorder( TreeNode* &f,TreeNode* &s,TreeNode* &P,TreeNode* A){
     if(A==NULL)return ;
     inorder(f,s,P,A->left);
     if(P!=NULL){
         if(P->val>A->val){
             if(f==NULL)
               f=P;
             s=A;
        } 
     }
     P=A;
     inorder(f,s,P,A->right);
     
 }
vector<int> Solution::recoverTree(TreeNode* A) {
    
    TreeNode* f=new TreeNode(0);
    TreeNode* s=new TreeNode(0);;
    TreeNode* P=new TreeNode(0);;
    inorder(f,s,P,A);
    vector<int>ans;
    
    ans={f->val,s->val};
    return ans;
    
}
