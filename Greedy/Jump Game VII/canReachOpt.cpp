class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        int farthestChecked = 0;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            int start =
                max(i + minJump,
                    farthestChecked + 1);

            int end =
                min(i + maxJump,
                    n - 1);

            for(int j = start; j <= end; j++)
            {
                if(s[j] == '0')
                {
                    if(j == n - 1)
                        return true;

                    q.push(j);
                }
            }

            farthestChecked =
                max(farthestChecked, end);
        }

        return n == 1;
    }
};
