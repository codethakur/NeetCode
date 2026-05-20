class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {


        // sort by pickup location
        sort(trips.begin(), trips.end(),
        [](auto &a, auto &b) {

            return a[1] < b[1];
        });


        // minHeap:
        // {dropLocation, passengers}

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;


        int currentPassengers = 0;


        for(auto &trip : trips) {

            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];


            // remove passengers who already left
            while(!minHeap.empty() &&
                  minHeap.top().first <= from) {

                currentPassengers -= minHeap.top().second;

                minHeap.pop();
            }


            // add new passengers
            currentPassengers += passengers;


            if(currentPassengers > capacity) {

                return false;
            }


            // push current trip
            minHeap.push({to, passengers});
        }

        return true;
    }
};
