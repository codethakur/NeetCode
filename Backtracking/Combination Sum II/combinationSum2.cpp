class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<vector<int>>ans;
        
        struct Frame
        {
            int i;
            int target;
            std::vector<int>temp;
        };
        stack<Frame>st;
        st.push({0, target, {}});
        while(!st.empty())
        {
            auto[i, tgt, temp] = st.top();
            st.pop();

            if(tgt == 0){
                ans.push_back(temp);
                continue;
            }
            if(tgt<0 || i>=candidates.size()) continue;

            for(int j = candidates.size()-1; j>=i; j--)
            {    
                if(j>i && candidates[j] == candidates[j-1]) continue;
                if(candidates[i]>tgt) continue;

                std::vector<int>next = temp;
                next.push_back(candidates[j]);

                st.push({j+1, tgt-candidates[j], next});
            }
        }
        return ans;
    }
};

#if 0
class Solution {
     void dfs(int i, vector<int>& candidates, int target,
             vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j<candidates.size(); j++)
        {
            if(j>i && candidates[j] == candidates[j-1]) continue;
            if(candidates[j]>target) break;

            temp.push_back(candidates[j]);
            dfs(j+1, candidates, target-candidates[j], temp, ans);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;

        dfs(0, candidates, target, temp, ans);
        return ans;
    }
};

#endif
