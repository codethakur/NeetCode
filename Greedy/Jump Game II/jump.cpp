class Solution {
    int dfs(vector<int>& nums, int i)
    {
        if(i>=nums.size()-1) return 0;
        int ans = INT_MAX;
        for(int jump = 1; jump<=nums[i]; jump++)
        {
            ans = min(ans, 1+dfs(nums, i+jump));
        }
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
