#if 0
class Solution {
public:

    vector<string> wordBreak(string s,
                             vector<string>& wordDict)
    {
        unordered_set<string> dict(
            wordDict.begin(),
            wordDict.end()
        );

        vector<string> ans;

        struct Frame {

            int idx;

            string sentence;
        };

        stack<Frame> st;

        // start from index 0
        st.push({0, ""});

        while (!st.empty())
        {
            auto [idx, sentence] = st.top();
            st.pop();

            // whole string consumed
            if (idx == s.size())
            {
                ans.push_back(sentence);
                continue;
            }

            // try every possible next word
            for (int end = s.size() - 1;
                 end >= idx;
                 end--)
            {
                string word =
                    s.substr(
                        idx,
                        end - idx + 1
                    );

                // not in dictionary
                if (!dict.count(word))
                    continue;

                string nextSentence;

                // first word
                if (sentence.empty())
                    nextSentence = word;
                else
                    nextSentence =
                        sentence + " " + word;

                st.push({
                    end + 1,
                    nextSentence
                });
            }
        }

        return ans;
    }
};
#endif
class Solution {

    void dfs(string& s,
             int idx,
             unordered_set<string>& dict,
             string sentence,
             vector<string>& ans)
    {
        // whole string consumed
        if (idx == s.size()) {
            ans.push_back(sentence);
            return;
        }

        // try every next word
        for (int end = idx;
             end < s.size();
             end++)
        {
            string word =
                s.substr(
                    idx,
                    end - idx + 1
                );

            // not valid word
            if (!dict.count(word))
                continue;

            string nextSentence;

            if (sentence.empty())
                nextSentence = word;
            else
                nextSentence =
                    sentence + " " + word;

            dfs(s,
                end + 1,
                dict,
                nextSentence,
                ans);
        }
    }

public:

    vector<string> wordBreak(
        string s,
        vector<string>& wordDict)
    {
        unordered_set<string> dict(
            wordDict.begin(),
            wordDict.end()
        );

        vector<string> ans;

        dfs(s,
            0,
            dict,
            "",
            ans);

        return ans;
    }
};
