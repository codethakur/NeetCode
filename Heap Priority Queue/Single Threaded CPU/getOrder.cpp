class Solution {
public:

    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();


        // -----------------------------------
        // Step 1:
        // Add original index
        // -----------------------------------

        vector<vector<int>> allTasks;

        for(int i = 0; i < n; i++) {

            // {enqueueTime, processingTime, index}

            allTasks.push_back({
                tasks[i][0],
                tasks[i][1],
                i
            });
        }


        // -----------------------------------
        // Step 2:
        // Sort by enqueue time
        // -----------------------------------

        sort(allTasks.begin(), allTasks.end());


        // -----------------------------------
        // Min Heap
        //
        // {processingTime, index}
        // -----------------------------------

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;


        vector<int> ans;

        long long time = 0;

        int i = 0;


        // -----------------------------------
        // Step 3:
        // Process tasks
        // -----------------------------------

        while(i < n || !minHeap.empty()) {


            // -----------------------------------
            // CPU idle?
            // Jump time forward
            // -----------------------------------

            if(minHeap.empty() && time < allTasks[i][0]) {

                time = allTasks[i][0];
            }


            // -----------------------------------
            // Push all available tasks
            // -----------------------------------

            while(i < n && allTasks[i][0] <= time) {

                int enqueueTime = allTasks[i][0];
                int processingTime = allTasks[i][1];
                int index = allTasks[i][2];

                minHeap.push({processingTime, index});

                i++;
            }


            // -----------------------------------
            // Pick shortest task
            // -----------------------------------

            auto top = minHeap.top();
            minHeap.pop();

            int processingTime = top.first;
            int index = top.second;


            // execute task

            time += processingTime;

            ans.push_back(index);
        }

        return ans;
    }
};
