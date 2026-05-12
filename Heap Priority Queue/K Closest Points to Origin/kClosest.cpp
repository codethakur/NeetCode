#if 0
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<pair<int, vector<int>>> arr;

        for (auto& p : points) {

            int x = p[0];
            int y = p[1];

            int dist = x * x + y * y;

            arr.push_back({dist, p});
        }

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
#endif
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int,int>>> maxHeap;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            maxHeap.push({dist, {x, y}});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while (!maxHeap.empty()) {

            auto point = maxHeap.top().second;

            ans.push_back({point.first, point.second});

            maxHeap.pop();
        }

        return ans;
    }
};
