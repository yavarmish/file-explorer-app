//Symmetric Tree

/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3  */


//logic

//we will need a utility function to solve it recursively
//consider two pointers both equal to root initially
//if both are null it's alright,if one of them is null return false
//if there values are'nt equal return false
//check this for p1->left,p2->right and p1->right,p2->left



class Solution {
public:
    
    bool Mirror(TreeNode* p1,TreeNode* p2)
    {
        if(!p1&&!p2)
            return true;
        if(!p1||!p2)
            return false;
        
        if(p1->val!=p2->val)
            return false;
        
        return Mirror(p1->left,p2->right)&&Mirror(p1->right,p2->left);
        
    }
        
    bool isSymmetric(TreeNode* root) {
        
        return Mirror(root,root);   
            
        
        
            
        
    }
};
