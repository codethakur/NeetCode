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
 
