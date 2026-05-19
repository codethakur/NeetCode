class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>> freqChar = {
            {a, 'a'},
            {b, 'b'},
            {c, 'c'}
        };        
        string ans = "";

        while(true)
        {
            // largest frequency first
            sort(freqChar.rbegin(), freqChar.rend());
            bool added = false;

            for(int i =0; i<3; i++)
            {
                char ch = freqChar[i].second;
                int count = freqChar[i].first;

                if(count ==0){
                    continue;
                }
                int n = ans.length();
                if(n>=2 && ch == ans[n-1] && ch == ans[n-2]){
                    continue;
                }
                ans+=ch;
                freqChar[i].first--;
                added = true;
                break;
            }
            if(!added){
                break;
            }
        }
        return ans;
    }
};
