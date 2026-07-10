class Solution {
    bool solve(int i, int open, string& s)
    {
        if(open < 0)
            return false;
        if(i == s.size())
            return open == 0;
        if(s[i] == '('){
            return solve(i+1, open+1, s);
        }
        if(s[i] == ')')
        {
            return solve(i+1, open-1, s );
        }

        bool useAsOpen =
            solve(i+1, open+1, s);
        bool useAsClose =
            solve(i+1, open-1, s);
        bool useAsEmpty =
            solve(i+1, open, s);
        return useAsOpen || useAsClose || useAsEmpty;
    }
public:
    bool checkValidString(string s) {
        return solve(0, 0, s);
    }
};
