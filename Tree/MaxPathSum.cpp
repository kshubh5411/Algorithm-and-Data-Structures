/**
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

Input:
The input contains T, denoting number of testcases. For each testcase there will be two lines. The first line contains number of edges. The second line contains two nodes and a character separated by space. The first node denotes data value, second node denotes where it will be assigned to the previous node which will depend on character 'L' or 'R' i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on. The first node of second line is root node. The struct or class Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, the function will be called individually.

Output:
Return the Maximum possible sum.

Constraints:
1 <=T <= 100
1 <= N <= 30

Example:
Input:
1
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L

Output:
27
**/
Solution:
int  maxPath(Node* root,int &res){
    if(!root)return 0;
    int l=maxPath(root->left,res);
    int r=maxPath(root->right,res);
    res=max(res,l+r+root->data);
    return max(l,r)+root->data;
}
int maxPathSum(struct Node *root)
{
    int res=0;
    int c=maxPath(root,res);
    // cout<<c<<endl;
    return res;
}



