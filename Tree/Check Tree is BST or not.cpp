bool check(Node* root,int min,int max){
    if(root==NULL) return true;
    if(root->data>max||root->data<min) return false;
    //if go to left update the max as we have to compare the current element with left element (which should be bigger)
    //Similarly when to go right we have to compare the curr element with right element which should be small
    return check(root->left,min,root->data)&check(root->right,root->data,max);
}
bool isBST(Node* root) {
    int min=INT_MIN,max=INT_MAX;
    return check(root,min,max);
}
