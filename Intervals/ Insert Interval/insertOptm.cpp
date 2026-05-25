class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd   = newInterval[1];

        vector<vector<int>> ans;
        
        int i = 0, n = intervals.size();

        while(i<n && intervals[i][1]< newStart)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<= newEnd)
        {
            newStart = min(newStart,  intervals[i][0]);
            newEnd = max(newEnd,  intervals[i][1]);
            i++;
        }
        ans.push_back({newStart, newEnd});

        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;

    }
};
