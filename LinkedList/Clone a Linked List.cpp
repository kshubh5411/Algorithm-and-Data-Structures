/**
You are given a Singly Linked List with N nodes where each node next pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1
Input:
First line of input contains number of testcases T. For each testcase, first line of input contains two integers N and M. Next line of input contains values of N nodes of the linked list and last line contains M pairs denoting arbitrary connecting  nodes, for which each ith node is connected to any jth node. ( ith->arb = jth )

NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Output:
For each testcase, clone the given linked list.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Example:
Input:
1           
4 2                                       
1 2 3 4                             
1 2 2 4

Output:
1

Explanation:
Testcase 1: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. The fourth line gives the information about arbitrary pointers. The first node arbit pointer is set to node 2.  The second node arbit pointer is set to node 4.
 
**/

Solution:
struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/
// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    map<int,pair<Node*,Node*>>mp;
    Node*c=new Node(head->data);
    Node* root=c;
    int i=0;
    while(head!=NULL){
       mp.insert({i,{head->arb,head->next}});
        // mp[i++]=make_pair(head->arb,head->next);
        i++;
        head=head->next;
    }
    for(auto i:mp){
        
        c->next=i.second.second;
        c->arb=i.second.first;
        c=c->next;
    }
    return  root;
}
