/** Check whether t2 is a subtree of t1 or not  
  Note: T2 must be present at leaf node of t1.
**/

#include<bits/stdc++.h>
void inorder( queue<Node*> &q,Node* h,int v){
    if(h==NULL)return;
    if(h->data==v){
        q.push(h);
    }
    inorder(q,h->left,v);
    inorder(q,h->right,v);
}
bool check(Node* h1,Node* h2){
    if((h1==NULL&&h2!=NULL)||(h2==NULL&&h1!=NULL)) return false;
    if(h1==NULL&&h2==NULL) return true;
    if(h1->data!=h2->data) return false;
    
    check(h1->left,h2->left);
    check(h1->right,h2->right);
}


bool isSubtree(Node* T1, Node* T2) {
    if(T1==NULL) return true;
    if(T2==NULL) return false;
    queue<Node*> q;
    inorder(q,T1,T2->data);
    
    while(!q.empty()){
        Node* h1=q.front();
        //cout<<"H-"<<h1->data<<endl;
        q.pop();
        bool c=check(h1,T2);
        if(c) return true;
    }
    return false;
    
}
