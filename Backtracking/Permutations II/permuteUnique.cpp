class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        std::sort(nums.begin(), nums.end());

        struct Frame {
            vector<int> temp;
            vector<bool> used;
        };

        stack<Frame> st;
        st.push({{}, vector<bool>(nums.size(), false)});


        while (!st.empty()) {
            auto [temp, used] = st.top();
            st.pop();

            if (temp.size() == nums.size()) {
                ans.push_back(temp);
                continue;
            }

            // reverse for recursion-like order
            for (int j = nums.size() - 1; j >= 0; j--) {

                if (used[j]) continue;

                // 🔥 duplicate handling
                if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1])
                    continue;

                vector<int> nextTemp = temp;
                vector<bool> nextUsed = used;

                nextTemp.push_back(nums[j]);
                nextUsed[j] = true;

                st.push({nextTemp, nextUsed});
            }
        }
        return ans;
    }
};
