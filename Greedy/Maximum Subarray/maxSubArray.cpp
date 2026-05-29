class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 0; i<nums.size(); i++)
        {
            int curSum = 0;
            for(int j = i; j<nums.size(); j++)
            {
                curSum += nums[j];
                sum = max(sum, curSum);
            }
        }
        return sum;
    }
};
