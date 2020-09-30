#include<bits/stdc++.h>
using namespace std;


// find the Kth node from the last

// logic 1 - kth node from last is (n-k+1)th node from the start
//requires 2 O(n) traversals(one to find length of linked list then to find kth node)

//logic 2 - use two pointers first send the first pointer to kth position
//then move both pointers till first pointer reaches the end.the second pointer 
//is the required position. 
//requires 1 O(n) traversal

int getNthFromLast(Node *head, int k)
{
       // Your code here
       Node* temp1=head;Node* temp2=head;
       int c=0;
       while(c!=k&&temp1!=NULL)
       {
           temp1=temp1->next;
           c++;
       }
       if(c!=k)
       return -1;
       
       while(temp1!=NULL)
       {
           temp1=temp1->next;
           temp2=temp2->next;
       }
       
       return temp2->data;
}

