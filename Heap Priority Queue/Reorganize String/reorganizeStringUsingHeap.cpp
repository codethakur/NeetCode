class Solution {
public:

    string reorganizeString(string s) {

        vector<int> freq(26, 0);

        for(char ch : s) {

            freq[ch - 'a']++;
        }
        priority_queue<pair<int,char>> maxHeap;

        for(int i =0; i<26; i++)
        {
            if(freq[i]>0)
            {
                maxHeap.push({freq[i], char(i+'a')});
            }

        }
        string ans = "";
       // previous character
        pair<int,char> prev = {0, '#'};
        while(!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            char ch = top.second;
            int count = top.first;

            ans+=ch;
            count--;

             // previous char becomes available again
            if(prev.first > 0) {

                maxHeap.push(prev);
            }
            prev = {count, ch};
        }
         // impossible case
        if(ans.length() != s.length()) {

            return "";
        }
        return ans;
    }
};
