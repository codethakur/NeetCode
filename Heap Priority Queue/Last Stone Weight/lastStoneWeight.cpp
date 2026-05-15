class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1)
        {
            std::sort(stones.begin(), stones.end());

            int x = stones.back(); stones.pop_back();
            int y = stones.back(); stones.pop_back();

            if(x!=y)
            {
                stones.push_back(x-y);
            }
            std::sort(stones.begin(), stones.end());
        }
        return stones.empty() ? 0 : stones[0];
    }
};
