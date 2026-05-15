class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>maxHeap;

        for(auto point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            maxHeap.push({dist, {x,y}});

            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>>ans;

        while(!maxHeap.empty())
        {
            auto topPoint = maxHeap.top().second;

            int x = topPoint.first;
            int y = topPoint.second;

            ans.push_back({x, y});

            maxHeap.pop();
        }
        return ans;

    }
};
