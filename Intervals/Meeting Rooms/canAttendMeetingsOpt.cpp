/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    static bool cmp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }

public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int prevEnd = intervals[0].end;

        for(int i =1; i<intervals.size(); i++)
        {   
            int start = intervals[i].start;
            int end   = intervals[i].end;

            if(prevEnd> start){
                return false;
            }else{
                prevEnd = end;
            }
        }
        return true;
    }
};
