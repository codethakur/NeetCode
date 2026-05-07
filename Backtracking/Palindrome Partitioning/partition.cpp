class Solution {

    bool isPalindrome(string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void dfs(string& s,
             int start,
             vector<string>& path,
             vector<vector<string>>& ans)
    {
        // whole string partitioned
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++)
        {
            // invalid substring
            if (!isPalindrome(s, start, end))
                continue;

            // choose
            path.push_back(
                s.substr(start, end - start + 1)
            );

            // explore
            dfs(s, end + 1, path, ans);

            // BACKTRACK (undo)
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        dfs(s, 0, path, ans);

        return ans;
    }
};
#if 0
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
#endif
