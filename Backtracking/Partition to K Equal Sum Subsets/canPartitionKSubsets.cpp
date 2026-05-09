class Solution {
public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        if (k > nums.size())
            return false;

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        struct Frame {
            int idx;
            vector<int> buckets;
        };

        stack<Frame> st;

        st.push({0, vector<int>(k, 0)});

        while (!st.empty()) {

            auto [idx, buckets] = st.top();
            st.pop();

            // all numbers placed
            if (idx == nums.size()) {

                bool ok = true;

                for (int x : buckets) {
                    if (x != target) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    return true;

                continue;
            }

            // try placing nums[idx] into each bucket
            for (int i = k - 1; i >= 0; i--) {

                // exceeds target
                if (buckets[i] + nums[idx] > target)
                    continue;

                // duplicate-state pruning
                if (i < k - 1 &&
                    buckets[i] == buckets[i + 1])
                    continue;

                vector<int> nextBuckets = buckets;

                nextBuckets[i] += nums[idx];

                st.push({idx + 1, nextBuckets});
            }
        }

        return false;
    }
};
