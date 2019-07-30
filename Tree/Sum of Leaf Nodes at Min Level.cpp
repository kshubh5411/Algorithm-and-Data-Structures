/**
Given a Binary Tree of size N, your task is to complete the function minLeafSum(), that should return the sum of all the leaf nodes that are at minimum level of the given binary tree.
Example:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \ 
 7    2      
Output :
sum = 5 + 8 = 13
Input:
The function takes a single arguments as input, the reference pointer to the root of the binary tree.
There are T test cases and for each test case the function will be called separately.

Output:
The function should return the sum of all the leaf nodes that are at the minimum level of the binary tree.

Constraints:
1<=T<=103
0<=N<=103

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
5
190
**/
Solution:
int minLeafSum(Node* root)
{
	// Code here
	if(root==NULL) return 0;
	if(!root->left&&!root->right)return root->data;
	queue<Node*>q;
	q.push(root);
	int s=0;
	int f=0;
	while(f==0){
	    int size=q.size();
	    while(size--){
	        Node* p=q.front();
	        q.pop();
	        if(!p->left&&!p->right){
	            s+=p->data;
	            f=1;
	        }else{
	            if(p->left){
	                q.push(p->left);
	            }
	            if(p->right){
	                q.push(p->right);
	            }
	        }
	    }
	}
	return s;
}
