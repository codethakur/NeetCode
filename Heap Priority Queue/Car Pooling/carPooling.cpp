class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int farthestLocation = 0;
        for(auto& trip : trips)
        {
            farthestLocation = max(farthestLocation, trip[2]);
        }

        std::vector<int>road(farthestLocation+1, 0);

        for(auto &trip : trips)
        {
            int passenger = trip[0];

            int from = trip[1];

            int to = trip[2];


            road[from] += passenger;

            road[to] -= passenger;
        }

        int currentPassenger = 0;
        for(int i =0; i<=farthestLocation; i++)
        {
            currentPassenger+=road[i];
            if(currentPassenger>capacity) return false;
        }

        return true;
    }
};
