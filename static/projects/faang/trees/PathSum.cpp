//Path Sum
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
//adding up all the values along the path equals the given sum.

//logic
//do a dfs and for evry leaf node check if sum of path
//is equal to given sum

class Solution {
public:
    
    void dfs(TreeNode* root,int sum,bool& ok,int& chap)
    {
        if(root==NULL)
            return;
        
        chap+=root->val;
        
        if(chap==sum&&root->left==NULL&&root->right==NULL)
        {ok=true;return;}
    	//recursion
        dfs(root->left,sum,ok,chap);        
        dfs(root->right,sum,ok,chap);
        //backtrack
        chap-=root->val;
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool ok=false;
        int chap=0;
        dfs(root,sum,ok,chap);
        return ok;
    }
};

//Path sum 2
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

//logic
//the ide is to pass another vector for maintaining cur path and 
//push the current vector into final ans if cur_sum=sum for a leaf node

class Solution {
public:
    void dfs(TreeNode* root,int sum,vector<int>cur,vector<vector<int>>& ans,int& cur_sum)
    {
        
        if(root==NULL)
        return;
        
        cur_sum+=root->val;
        cur.push_back(root->val);
        if(!root->left&&!root->right&&cur_sum==sum)
        ans.push_back(cur);
        
        
        
        dfs(root->left,sum,cur,ans,cur_sum);
        dfs(root->right,sum,cur,ans,cur_sum);
        cur_sum-=root->val;
        
        
        
            
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        int k=0;
        dfs(root,sum,cur,ans,k);
        return ans;
    }
};

//Path sum 3
/*You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.*/


//logic
//we use same logic as subarray with given sum we maintain a map and calculate prefix sum 
//if prefix sum(cur_sum) is equal to target we increment the answer,if cur_sum-sum exists in the array this means we
//have encounterd a prefix array with cur_sum-sum,therefore we will get an answer subarray if we subtract current subarray
//from that sub array,hence we increment ans by m[cur_sum-sum] (i.e. count of such arrays)


class Solution {
public:
    void dfs(TreeNode* root,int sum,int& ans,int cur_sum,unordered_map<int,int>& m)
    {
        if(root==NULL)
            return;
        
        cur_sum+=root->val;
        
        
        
        if(cur_sum==sum)
        ans++;
        if(m.find(cur_sum-sum)!=m.end())
        ans+=m[cur_sum-sum];
        
        m[cur_sum]++;
        
        dfs(root->left,sum,ans,cur_sum,m);
        dfs(root->right,sum,ans,cur_sum,m);
        
        m[cur_sum]--;
        
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        int cur_sum=0;
        unordered_map<int,int> m;
        dfs(root,sum,ans,cur_sum,m);
        return ans;
    }
};
