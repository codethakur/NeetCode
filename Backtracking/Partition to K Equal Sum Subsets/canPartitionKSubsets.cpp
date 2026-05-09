#if 0
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
#endif 

class Solution {

    bool dfs(vector<int>& nums, int k, int target, int idx, vector<int>& buckets)
    {
        // all numbers placed
        if (idx == nums.size())
            return true;

        for (int i = 0; i < k; i++)
        {
            // exceeds target
            if (buckets[i] + nums[idx] > target)
                continue;

            // skip duplicate bucket states
            if (i > 0 &&
                buckets[i] == buckets[i - 1])
                continue;

            // choose
            buckets[i] += nums[idx];

            // explore
            if (dfs(nums, k, target,
                    idx + 1, buckets))
                return true;

            // BACKTRACK
            buckets[i] -= nums[idx];
        }

        return false;
    }

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

        vector<int> buckets(k, 0);

        return dfs(nums, k, target, 0, buckets);
    }
};
