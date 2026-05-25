class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();

        for(int i = 1; i<n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int lastEnd = ans.back()[1];

            // overlap
            if (start <= lastEnd)
            {
                ans.back()[1] = max(lastEnd, end);
            }
            // no overlap
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
