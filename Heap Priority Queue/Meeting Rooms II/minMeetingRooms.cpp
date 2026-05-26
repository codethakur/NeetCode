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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxRoom = 0;
        for(auto meeting : intervals)
        {
            int currTime = meeting.start;
            int room = 0;
            for(auto other : intervals)
            {
                if(other.start<= currTime && currTime<other.end)
                {
                    room++;
                }
            }
            maxRoom = max(maxRoom, room);
        }
        return maxRoom;
    }
};
