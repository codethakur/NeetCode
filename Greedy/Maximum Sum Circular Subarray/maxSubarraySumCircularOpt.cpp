class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int curMax = 0;
        int maxSum = nums[0];

        int curMin = 0;
        int minSum = nums[0];

        for (int num : nums)
        {
            totalSum += num;

            // Kadane for maximum subarray
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            // Kadane for minimum subarray
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);
        }

        // All numbers are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};
