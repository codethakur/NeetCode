class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        struct Frame {
            int i;
            int target;
            vector<int> temp;
        };

        stack<Frame> st;
        st.push({0, target, {}});

        while (!st.empty()) {
            Frame cur = st.top();
            st.pop();

            int i = cur.i;
            int tgt = cur.target;
            vector<int> temp = cur.temp;

            // base cases
            if (tgt == 0) {
                ans.push_back(temp);
                continue;
            }

            if (i >= nums.size() || tgt < 0) {
                continue;
            }

            // 🔁 IMPORTANT: push in reverse order
            // because stack is LIFO

            // 1. skip branch
            st.push({i + 1, tgt, temp});

            // 2. take branch
            temp.push_back(nums[i]);
            st.push({i, tgt - nums[i], temp});
        }

        return ans;
    }
};


#if 0
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break; 

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, ans); 
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, ans);
        return ans;
    }
};
#endif
