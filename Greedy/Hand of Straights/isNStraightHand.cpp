class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        vector<bool> taken(n, false);

        for(int i = 0; i < n; i++)
        {
            if(taken[i]) continue;

            taken[i] = true;

            int need = hand[i] + 1;

            for(int k = 1; k < groupSize; k++)
            {
                bool found = false;

                for(int j = 0; j < n; j++)
                {
                    if(!taken[j] &&
                       hand[j] == need)
                    {
                        taken[j] = true;
                        found = true;
                        need++;
                        break;
                    }
                }

                if(!found)
                    return false;
            }
        }

        return true;
    }
};
