class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        struct Frame
        {
            int start;
            vector<int>temp;
        };

        stack<Frame>st;
        st.push({0, {}});

        while(!st.empty())
        {
            auto[start, temp]  = st.top();
            st.pop();

            ans.push_back(temp);

            for(int j = nums.size()-1; j>=start; j--)
            {
                // skip duplicates
                if (j > start && nums[j] == nums[j - 1]) continue;
                vector<int>next= temp;
                next.push_back(nums[j]);
                st.push({j+1, next});
            }
        }
        return ans;
    }
};
