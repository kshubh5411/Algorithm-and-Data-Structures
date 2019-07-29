//Flatten Multi Level Linked List
void flattenLinkedList(Node* head){
    Node* curr=head;
    Node* tail=curr;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    while(curr!=temp){
        if(curr->child){
          tail->next=curr->child;
          Node* temp=curr->child;
          while(temp->next!=NULL)temp=temp->next;
          tail=temp;
        }
        curr=curr->next;
        
    }
    return head;
}
