class Solution {
public:

    int solve(vector<vector<int>>& intervals,
              int index,
              int prevEnd)
    {
        // all intervals processed
        if(index == intervals.size())
        {
            return 0;
        }

        int start = intervals[index][0];
        int end   = intervals[index][1];

        // NO overlap
        if(start >= prevEnd)
        {
            return solve(intervals, index + 1, end);
        }

        // OVERLAP
        else
        {
            // OPTION 1:
            // remove current interval
            int removeCurrent =
                1 + solve(intervals,
                          index + 1,
                          prevEnd);

            // OPTION 2:
            // remove previous interval
            int removePrevious =
                1 + solve(intervals,
                          index + 1,
                          end);

            return min(removeCurrent,
                       removePrevious);
        }
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        return solve(intervals,
                     1,
                     intervals[0][1]);
    }
};
