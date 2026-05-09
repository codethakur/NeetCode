class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k>nums.size()) return false;

        int sum = 0;
        for(int x : nums)
        {
            sum += x;
        }
        if(sum%k != 0) return false;

        int target = sum/k;

        std::sort(nums.rbegin(), nums.rend());
        if(nums[0]>target) return false;

        struct Frame
        {
            int idx;
            vector<int>temp;
        };

        stack<Frame>st;
        st.push({0, {}});
        while(!st.empty())
        {
            auto[idx,  temp] = st.top();
            st.pop();

            if(idx == nums.size()){
                return true;
            }

           for(int i = k; i>=0; i--)
           {
                if(i<k && temp[j] + temp[j-1] >target) continue;

                temp[j] = nums[idx];
                st.push({idx+1, temp});
           }
        }

    }
};
