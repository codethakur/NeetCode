class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> numFreq;

        for(auto& num : hand)
        {
            numFreq[num]++;
        }

        for(int i = 0; i < n; i++)
        {
            int start = hand[i];

            if(numFreq[start] == 0)
                continue;

            for(int current = start; current < start + groupSize; current++)
            {
                if(numFreq[current] == 0)
                    return false;

                numFreq[current]--;
            }
        }

        return true;
    }
};
