class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        vector<int>ans;
        for(auto& querie :queries)
        {
            int length = -1;
            for(auto& interval : intervals)
            {
                int start = interval[0];
                int end = interval[1];

                if(querie >= start && querie<= end)
                {
                    if(length == -1 || (end-start)+1 < length )
                        length =  (end-start)+1;
                }

            }
            ans.push_back(length);
        }
        return ans;
    }
};
