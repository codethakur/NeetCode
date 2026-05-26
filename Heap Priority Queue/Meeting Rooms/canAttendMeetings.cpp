class Solution {
public:

    bool canAttendMeetings(vector<Interval>& intervals)
    {
        int n = intervals.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int start1 = intervals[i].start;
                int end1   = intervals[i].end;

                int start2 = intervals[j].start;
                int end2   = intervals[j].end;

                // overlap exists
                if(max(start1, start2) < min(end1, end2))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
