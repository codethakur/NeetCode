class Solution {
public:
    string predictPartyVictory(string senate) {

        int n = senate.size();

        queue<int> rQueue;
        queue<int> dQueue;

        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
                rQueue.push(i);
            else
                dQueue.push(i);
        }

        while(!rQueue.empty() && !dQueue.empty())
        {
            int r = rQueue.front();
            rQueue.pop();

            int d = dQueue.front();
            dQueue.pop();

            if(r < d)
            {
                // R acts first, bans D
                rQueue.push(r + n);
            }
            else
            {
                // D acts first, bans R
                dQueue.push(d + n);
            }
        }

        return rQueue.empty() ? "Dire" : "Radiant";
    }
};
