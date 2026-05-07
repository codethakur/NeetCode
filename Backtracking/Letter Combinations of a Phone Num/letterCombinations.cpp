#if 0
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        struct Frame
        {
            int idx;
            string temp;
        };
        stack<Frame>st;
        st.push({0, {}});

        while (!st.empty()) {

            auto [idx, temp] = st.top();
            st.pop();

            // complete combination formed
            if (idx == digits.size()) {
                ans.push_back(temp);
                continue;
            }

            string letters = mp[digits[idx]];

            // reverse loop because stack is LIFO
            for (int i = letters.size() - 1; i >= 0; i--) {

                st.push({
                    idx + 1,
                    temp + letters[i]
                });
            }
        }

        return ans;
    }
};
#endif

class Solution {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void dfs( string digits, int idx, string& temp,vector<string>& ans)
    {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[idx]];
        // iterate current digit letters
        for (int i = 0; i < letters.size(); i++)
        {
            temp.push_back(letters[i]);

            // move to next digit
            dfs(digits, idx + 1, temp, ans);

            // BACKTRACK
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> ans;
        string temp;

        dfs(digits, 0, temp, ans);

        return ans;
    }
};

