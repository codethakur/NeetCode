class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,
                           vector<int>& cost) {

        int n = gas.size();

        for(int start = 0; start < n; start++)
        {
            int tank = 0;
            bool valid = true;

            for(int step = 0; step < n; step++)
            {
                int i = (start + step) % n;

                tank += gas[i];
                tank -= cost[i];

                if(tank < 0)
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
                return start;
        }

        return -1;
    }
};
