/** 1 2 3 4 5 
    1 5 2 4 3
    1 2 3 4 5 n-1 n
    1 n 2 n-1 3 n-3.....
 **/
 
 Node* reverse(Node *h){
    Node* curr=h;
    Node* prev=NULL;
    Node* next=NULL;
    while(h!=NULL){
        h=h->next;
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    return prev;
}
void reorderList(Node* head) 
{
    int n=0;
    Node* A=head;
    while(A!=NULL){
        A=A->next;
        n++;
    }
    if(n<=2) return;
    Node* C;
    Node* h1=head;
    Node* h2;
    A=head;
    Node* D;
    {
        for(int i=0;i<n/2;i++){
            h1=h1->next;
        }
        h2=h1->next;
        h1->next=NULL;
        Node* B=reverse(h2);
        //  while(B!=NULL){ cout<<B->data<<" ";B=B->next;}
        while(A!=NULL&&B!=NULL){
            D=B;
            B=B->next;
            D->next=A->next;
            C=A;
            A=A->next;
            C->next=D;
        }
    }
}
