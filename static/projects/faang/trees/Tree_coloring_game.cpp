//Binary Tree Coloring Game

/*Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false.*/

//logic

//first we will find the red node in the binary tree,then we will count its left and right node
//we want to find a node such that flood filling it will have more nodes than flood filling red
//which is only possible if l>u+r or u>l+r or r>l+u
//where l=left nodes of red, r=right nodes of red, u=rest of the nodes

class Solution {
public:
    
    TreeNode* find(TreeNode* root,int x)
    {
        if(root==NULL)
            return NULL;
        
        if(root->val==x)
            return root;
        TreeNode* left=find(root->left,x);
        
        if(left==NULL)
            return find(root->right,x);
        
        return left;
        
    }
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode* red=find(root,x);
        int up,l,r;
        l=count(red->left);
        r=count(red->right);
        up=n-l-r-1;
        if(up>l+r||l>up+r||r>l+up)
            return true;
        return false;
        
    }
};



