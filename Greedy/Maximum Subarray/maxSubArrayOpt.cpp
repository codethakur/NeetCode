class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int curSum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(curSum < 0)
                curSum = 0;
            curSum += nums[i];
            sum = max(sum, curSum);
        }
        return sum;
    }
};
