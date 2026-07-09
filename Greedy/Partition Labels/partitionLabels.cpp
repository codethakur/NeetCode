class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<int>ans;
        int n = s.length();
        int start = 0;
        while(start<n)
        {
            int end = start;
            for(int i=start; i<=end; i++)
            {
                for(int j = n-1; j>=0; j--)
                {
                    if(s[j]==s[i])
                    {
                        end= max (end, j);
                        break;
                    }
                }
            }
            ans.push_back(end-start+1);
            start = end+1;
        }
        return ans;

    }
};
