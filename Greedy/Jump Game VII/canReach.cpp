class Solution {
    bool dfs(int i, string s, int minJump, int maxJump) {
        int n = s.size();
        if(i == n-1) return true;

        for(int j = i+minJump; j<=min(i+maxJump, n-1); j++)
        {
            if(s[j] == '0')
            {
                if(dfs(j, s, minJump, maxJump)) return true;
            }
        }
        return false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        return dfs(0, s, minJump, maxJump);
    }
};
