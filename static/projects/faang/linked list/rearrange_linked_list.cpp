//rearrange linked list

// Given a singly linked list, the task is to rearrange it in a way that all 
// odd position nodes are together and all even positions node are together.


//logic
//store the link for first even node(to be assigned as link of last odd node)
//first assign link of odd node as link of even node(odd->next=even->next) and then move the odd 
//node pointer to next odd node(odd=even->next) and then do the same for even node
//do this while the above node exists and finally assign link of odd node as first even node

Node *rearrangeEvenOdd(Node *head)
{
   
   
   Node*odd=head;
   Node*even=head->next;
   Node*ef=even;
   while(odd&&even&&odd->next&&even->next)
   {
       odd->next=even->next;
       odd=even->next;
       even->next=odd->next;
       even=odd->next;
   }
   odd->next=ef;
   
   return head;
}