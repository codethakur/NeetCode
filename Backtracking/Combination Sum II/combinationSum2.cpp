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
