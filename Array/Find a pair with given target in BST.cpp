/**
Given a Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, otherwise return false.

Input:
First line consists of T test cases. First line of every test case consists of N and target, denoting the number of elements in bst and target sum. Second line consists of elements of BST.

Output:
Return True if target sum pair is found else False.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
7 10
1 2 3 4 5 6 7
7 33
15 10 20 8 12 16 25  
Output:
1
1
 
**/

Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
void inorder(node* root,vector<int>&A){
    if(root==NULL) return;
    inorder(root->left,A);
    A.push_back(root->val);
    inorder(root->right,A);
}
bool isPairPresent(struct node *root, int k)
{
   vector<int> arr;
   inorder(root,arr);
   int n=arr.size();
   int i=0,j=n-1;
   while(i<j){
       if(arr[i]+arr[j]>k){
           j--;
       }else if(arr[i]+arr[j]<k)i++;
       else return true;
   }
   return false;
   
