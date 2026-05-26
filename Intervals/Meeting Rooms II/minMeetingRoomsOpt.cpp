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
    int minMeetingRooms(vector<Interval>& intervals) {
        // edge case
        if(intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int>>minHeap;
        minHeap.push(intervals[0].end);

        for(int i = 1; i<intervals.size(); i++)
        {
            int start = intervals[i].start;
            int end   = intervals[i].end;

            if(start>=minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(end);
        }
        return minHeap.size();
    }
};
