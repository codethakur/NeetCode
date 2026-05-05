#if 0
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
#endif
class Solution {
    void Backtracking(int start, int n, int k, vector<int>& temp,vector<vector<int>>& ans)
    {
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i<=n; i++)
        {
            temp.push_back(i);
            Backtracking(i + 1, n, k, temp, ans); 

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        Backtracking(1, n, k, temp, ans);
        return ans;
    }
};
