//Count Number of SubTrees having given Sum
//Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() 
//that returns the count of the number of subtress having total node’s data sum equal to the value X.

// logic
//approach 1(using 2 functions)
// use a utility function which increments the count each time such subtree is observed

//approach 2(using 1 function)
//in a single function use a static count and static pointer for root when root reaches itself again 
//return count
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

//approach 1

int countSubtreesWithSumXutil(Node* root,int& c,int x)
{
	if(root==NULL)
		return 0;
	
	int ls=countSubtreesWithSumXutil(root->left,c,x);
	int rs=countSubtreesWithSumXutil(root->right,c,x);

	if(ls+rs+root->data==x)
		c++;

	return ls+rs+root->data;

}
int countSubtreesWithSumX(Node* root, int x) 
{ 
	int count =0;
	if(root==NULL)
		return 0;

	int ls=0,rs=0;

	ls+=countSubtreesWithSumXutil(root,c,x);
	rs+=countSubtreesWithSumXutil(root,c,x);

	if(ls+rs+root->data==x)
		c++;
	return c;
} 



//approach 2
// int countSubtreesWithSumX(Node* root, int x) 
// { 
// 	static int count =0;
// 	Node* p=root;
// 	if(root==NULL)
// 		return 0;

// 	int ls=0;int rs=0;

// 	ls+=countSubtreesWithSumX(root->left,x);
// 	rs+=countSubtreesWithSumX(root->right,x);

// 	if(ls+rs+root->data==x)
// 		c++;

// 	if(p!=root)
// 		return ls+rs+root->data;

// 	return c;

	
// } 
