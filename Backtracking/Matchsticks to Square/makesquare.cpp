#if 0
class Solution {
public:

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        // impossible immediately
        if (matchsticks[0] > target)
            return false;

        struct Frame {
            int idx;
            vector<int> sides;
        };

        stack<Frame> st;

        st.push({0, vector<int>(4, 0)});

        while (!st.empty()) {

            auto [idx, sides] = st.top();
            st.pop();

            // all sticks used
            if (idx == matchsticks.size()) {

                if (sides[0] == target &&
                    sides[1] == target &&
                    sides[2] == target &&
                    sides[3] == target)
                    return true;

                continue;
            }

            // try placing current stick
            for (int j = 3; j >= 0; j--) {

                // exceeds side length
                if (sides[j] + matchsticks[idx] > target)
                    continue;

                //  duplicate state pruning
                if (j < 3 && sides[j] == sides[j + 1])
                    continue;

                vector<int> nextSides = sides;

                nextSides[j] += matchsticks[idx];

                st.push({idx + 1, nextSides});
            }
        }

        return false;
    }
};
#endif
class Solution {

    bool dfs(vector<int>& matchsticks,
             int idx,
             vector<int>& sides,
             int target)
    {
        // all sticks used
        if (idx == matchsticks.size()) {

            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        // try placing current stick into each side
        for (int j = 0; j < 4; j++)
        {
            // exceeds target
            if (sides[j] + matchsticks[idx] > target)
                continue;

            // duplicate-state pruning
            if (j > 0 && sides[j] == sides[j - 1])
                continue;

            // choose
            sides[j] += matchsticks[idx];

            // explore
            if (dfs(matchsticks, idx + 1, sides, target))
                return true;

            // BACKTRACK (undo)
            sides[j] -= matchsticks[idx];
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        // impossible immediately
        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return dfs(matchsticks, 0, sides, target);
    }
};
