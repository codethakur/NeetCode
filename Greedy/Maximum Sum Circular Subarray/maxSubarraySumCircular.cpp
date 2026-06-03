class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans  = nums[0];
        int n = nums.size();
        for(int i =0; i<nums.size(); i++)
        {
            int currSum = 0;
            for(int j = i; j<i+nums.size(); j++)
            {
                currSum += nums[j%n];
                ans=max(ans, currSum);
            }
        }
        return ans;
    }
};
