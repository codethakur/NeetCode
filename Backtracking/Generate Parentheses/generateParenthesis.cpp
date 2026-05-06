#if 0
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       struct Frame
       {
            string s;
            int open;
            int close;
       };
       stack<Frame>st;
       st.push({"", 0, 0});

       while(!st.empty())
       {
            auto[s, open, close] = st.top();
            st.pop();
            if(s.size() == 2*n)
            {
                ans.push_back(s);
                continue;
            }

            if(close<open){
                st.push({s+ ")", open, close+1});
            }
            if(open<n)
            {
                st.push({s+"(", open+1, close});
            }
       }
       return ans;

    }
};
#endif
class Solution {
    void dfs(int open, int close, int n,string s, vector<string>& ans)
    {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // add '('
        if (open < n)
            dfs(open + 1, close, n, s + "(", ans);

        // add ')'
        if (close < open)
            dfs(open, close + 1, n, s + ")", ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, n, "", ans);
        return ans;
    }
};

 
