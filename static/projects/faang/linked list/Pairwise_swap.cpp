//Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
//For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.


//logic 
//take 2 jumps evrytime and swap data of current and next node
//O(n)

Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    Node* temp=head;
    while(temp&&temp->next)
    {
        int d2=temp->data;
        
        temp->data=temp->next->data;
        temp->next->data=d2;
        temp=temp->next->next;
        
    }
    return head;
}