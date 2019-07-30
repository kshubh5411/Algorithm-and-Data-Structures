TreeNode* buildT(vector<int> &A, vector<int> &B,int p,int q,int j){
          if(p>q) return NULL;  
          TreeNode* C=new TreeNode(B[j]);
        //   if(p==q) return  C;
          int id;
            for(int i=p;i<=q;i++){
                if(A[i]==B[j]){id=i;break;}};
            
            C->right=buildT(A,B,id+1,q,j-1);
            C->left=buildT(A,B,p,id-1,j-(q-id)-1);
            return C;
        
    }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
        int n=A.size();
        TreeNode* C=buildT(A,B,0,n-1,n-1);
        return C;
}
