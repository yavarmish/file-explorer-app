// 2 pointer approach
// greedy


// start with max length i.e. p1=0,p2=n-1 and move the pointers till p1<p2 accrding to one which is having minimum height

class Solution {
public:
    int maxArea(vector<int>& height) {
     
        int n=height.size();
        int p1=0,p2=n-1;
        int ans=0;
        while(p2>p1)
        {
            ans=max(ans,(p2-p1)*min(height[p1],height[p2]));
            if(height[p1]<=height[p2])
                p1++;
            else p2--;
            
        }
        return ans;
    }
};