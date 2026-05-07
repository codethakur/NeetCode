class Solution {
    bool isPlaindrome(string& s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;

        struct Frame
        {
            int start;
            vector<string>path;
        };

        stack<Frame>st;
        st.push({0, {}});

        while(!st.empty())
        {
            auto[start, path] = st.top();
            st.pop();

            if(start == s.size()){
                ans.push_back(path);
                continue;
            }

            for(int end = s.size()-1; end>=start; end--)
            {
                if(!isPlaindrome(s, start, end)) continue;

                vector<string>nextPath = path;

                  nextPath.push_back(
                    s.substr(start, end - start + 1)
                );

                st.push({end+1, nextPath});
            }
        }
        return ans;
    }
};
