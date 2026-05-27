class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // roomEnd[i] = when room i becomes free
        vector<long long> roomsEnd(n, 0);

        // count meetings handled by each room
        vector<int> meetingCount(n, 0);

        for(auto& meting : meetings)
        {
            int start = meting[0];
            int end = meting[1];

            int duration = end - start;
            int chosenRoom = -1;

            for(int room = 0; room<n; room++)
            {
                if(roomsEnd[room] <= start)
                {
                    chosenRoom = room;
                    break;
                }
            }
            if(chosenRoom!=-1)
            {
                roomsEnd[chosenRoom] = end;
            }
            else
            {
                long long  earliestEnd = roomsEnd[0];
                chosenRoom  = 0;
                for(int room = 1; room<n; room++)
                {
                    if(roomsEnd[room]<earliestEnd)
                    {
                        earliestEnd = roomsEnd[room];
                        chosenRoom = room;
                    }
                }
                roomsEnd[chosenRoom] = earliestEnd + duration;
            }
            meetingCount[chosenRoom]++;
        }
        int ans = 0;
        for(int room =1; room<n; room++)
        {
            if(meetingCount[room]>meetingCount[ans])
            {
                ans = room;
            }
        }
        return ans;

    }
};
