class Solution {
    bool dfs(vector<int>& nums, int i)
    {
        if(i>= nums.size() -1) return true;

        for(int jump = 1; jump<=nums[i]; jump++)
        {
            if(dfs(nums, i+jump)) 
                return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
