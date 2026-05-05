#if 0
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        std::vector<std::vector<int>>ans;


        struct Frame {
            vector<int> temp;
            vector<bool> used;
        };

        stack<Frame> st;
        st.push({{}, vector<bool>(nums.size(), false)});

        while(!st.empty())
        {
            auto[temp, used] = st.top();
            st.pop();

            if(temp.size() == nums.size()){
                ans.push_back(temp);
                continue;
            }
             // reverse loop for correct order
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (used[i]) continue;

                vector<int> nextTemp = temp;
                vector<bool> nextUsed = used;

                nextTemp.push_back(nums[i]);
                nextUsed[i] = true;

                st.push({nextTemp, nextUsed});
            }
        }
        return ans;

    }
};
#endif
class Solution {
    void dfs(vector<int>& nums, vector<bool>& used,
         vector<int>& temp, vector<vector<int>>& ans) {

    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        temp.push_back(nums[i]);

        dfs(nums, used, temp, ans);

        temp.pop_back();      // backtrack
        used[i] = false;
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        dfs(nums, used, temp, ans);
        return ans;
        
    }
};
