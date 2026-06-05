class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int jump = 0;

        while(right<nums.size()-1)
        {
            int farthest = 0;
            for(int i = left; i<=right; i++)
            {
                farthest = max(farthest, i+nums[i]);
            }
            left = right+1;
            right = farthest;

            jump++;
        }
        return jump;
    }
};
