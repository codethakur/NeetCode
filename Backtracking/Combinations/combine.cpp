class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        
        struct Frame {
            int start;
            vector<int> temp;
        };

        stack<Frame> st;
        st.push({1, {}});


        while (!st.empty()) {
            auto [start, temp] = st.top();
            st.pop();

            if (temp.size() == k) {
                ans.push_back(temp);
                continue;
            }

            // push in reverse so smaller numbers come first
            for (int i = n; i >= start; i--) {
                vector<int> next = temp;
                next.push_back(i);
                st.push({i + 1, next});
            }
        }

        return ans;
    }
};
