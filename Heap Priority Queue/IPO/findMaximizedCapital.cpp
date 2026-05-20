class Solution {
public:

    int findMaximizedCapital(
        int k,
        int w,
        vector<int>& profits,
        vector<int>& capital
    ) {

        int n = profits.size();


        // {capitalNeeded, profit}
        vector<pair<int,int>> projects;


        for(int i = 0; i < n; i++) {

            projects.push_back({
                capital[i],
                profits[i]
            });
        }


        // sort by capital needed
        sort(projects.begin(), projects.end());


        // max heap for profits
        priority_queue<int> maxHeap;


        int i = 0;


        while(k--) {


            // push all affordable projects
            while(i < n && projects[i].first <= w) {

                maxHeap.push(projects[i].second);

                i++;
            }


            // no project possible
            if(maxHeap.empty()) {
                break;
            }


            // take most profitable project
            w += maxHeap.top();

            maxHeap.pop();
        }

        return w;
    }
};
