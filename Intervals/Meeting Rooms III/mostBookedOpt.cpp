class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());

        // roomEnd[i] = when room i becomes free
        vector<long long> roomEnd(n, 0);

        // count meetings handled by each room
        vector<int> meetingCount(n, 0);

        for(auto meeting : meetings)
        {
            long long start = meeting[0];
            long long end   = meeting[1];

            long long duration = end - start;

            int chosenRoom = -1;

            // find free room
            for(int room = 0; room < n; room++)
            {
                if(roomEnd[room] <= start)
                {
                    chosenRoom = room;
                    break;
                }
            }

            // free room found
            if(chosenRoom != -1)
            {
                roomEnd[chosenRoom] = end;
            }
            else
            {
                // delay meeting
                long long earliestEnd = roomEnd[0];
                chosenRoom = 0;

                for(int room = 1; room < n; room++)
                {
                    if(roomEnd[room] < earliestEnd)
                    {
                        earliestEnd = roomEnd[room];
                        chosenRoom = room;
                    }
                }

                roomEnd[chosenRoom] =
                    earliestEnd + duration;
            }

            meetingCount[chosenRoom]++;
        }

        // find room with maximum meetings
        int answer = 0;

        for(int room = 1; room < n; room++)
        {
            if(meetingCount[room] >
               meetingCount[answer])
            {
                answer = room;
            }
        }

        return answer;
    }
};
