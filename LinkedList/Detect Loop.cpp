int detectloop(Node *head) {
    if(head==NULL) return 0;
     map<Node*,int> mp;
    while(head!=NULL){
        if(mp.find(head)!=mp.end())
        {
            return 1;
            
        }
        else mp.insert(make_pair(head,1));
        head=head->next;
    } return 0;
    }
//=========================================

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
int detectloop(Node *head) {
    if(head==NULL) return 0;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return 1;
    }
    
    return 0;
    
}
