class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1:
        // Count frequency of every task

        vector<int> freq(26, 0);

        for(char ch : tasks) {
            freq[ch - 'A']++;
        }


        // Step 2:
        // Max Heap
        //
        // Always execute task
        // having highest remaining frequency

        priority_queue<int> maxHeap;

        for(int f : freq) {
            if(f > 0) {
                maxHeap.push(f);
            }
        }


        // Step 3:
        // Queue for cooldown
        //
        // {remainingFrequency, timeWhenTaskBecomesAvailable}

        queue<pair<int, int>> q;


        int time = 0;


        // Step 4:
        // Run until both become empty

        while(!maxHeap.empty() || !q.empty()) {

            time++;


            // ---------------------------------
            // Execute task from heap
            // ---------------------------------

            if(!maxHeap.empty()) {

                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;


                // still remaining
                // put into cooldown queue

                if(cnt > 0) {

                    q.push({cnt, time + n});
                }
            }


            // ---------------------------------
            // Cooldown finished?
            // Move back into heap
            // ---------------------------------

            if(!q.empty() && q.front().second == time) {

                maxHeap.push(q.front().first);

                q.pop();
            }
        }

        return time;
    }
};
