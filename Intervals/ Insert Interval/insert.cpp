class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int newStart = newInterval[0];
        int newEnd   = newInterval[1];

        vector<vector<int>> ans;
        bool inserted = false;

        for (auto interval : intervals)
        {
            int start = interval[0];
            int end   = interval[1];

            // CASE 1
            // current interval completely before newInterval
            if (end < newStart)
            {
                ans.push_back(interval);
            }

            // CASE 2
            // current interval completely after newInterval
            else if (newEnd < start)
            {
                if (!inserted)
                {
                    ans.push_back({newStart, newEnd});
                    inserted = true;
                }

                ans.push_back(interval);
            }

            // CASE 3
            // overlap
            else
            {
                newStart = min(newStart, start);
                newEnd   = max(newEnd, end);
            }
        }

        // if still not inserted
        if (!inserted)
        {
            ans.push_back({newStart, newEnd});
        }

        return ans;
    }
};
