class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<bool> banned(n, false);

        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                if (banned[i])
                    continue;

                char enemy = (senate[i] == 'R') ? 'D' : 'R';
                bool foundEnemy = false;

                for (int j = 1; j < n; j++)
                {
                    int idx = (i + j) % n;

                    if (!banned[idx] && senate[idx] == enemy)
                    {
                        banned[idx] = true;
                        foundEnemy = true;
                        break;
                    }
                }

                if (!foundEnemy)
                {
                    return senate[i] == 'R' ? "Radiant" : "Dire";
                }
            }
        }
    }
};
