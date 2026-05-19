class Solution {
public:

    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> maxHeap;

        
        if(a > 0) {
            maxHeap.push({a, 'a'});
        }

        if(b > 0) {
            maxHeap.push({b, 'b'});
        }

        if(c > 0) {
            maxHeap.push({c, 'c'});
        }


        string ans = "";


        while(!maxHeap.empty()) {


            // best character
            auto top = maxHeap.top();
            maxHeap.pop();


            int count = top.first;
            char ch = top.second;


            int n = ans.length();


            // ---------------------------------
            // Would create aaa / bbb / ccc ?
            // ---------------------------------

            if(n >= 2 &&
               ans[n - 1] == ch &&
               ans[n - 2] == ch) {


                // no alternative character
                if(maxHeap.empty()) {
                    break;
                }


                // second best character
                auto secondTop = maxHeap.top();
                maxHeap.pop();


                int secondCount = secondTop.first;
                char secondChar = secondTop.second;


                // use second character
                ans += secondChar;

                secondCount--;


                // still remaining?
                if(secondCount > 0) {

                    maxHeap.push({
                        secondCount,
                        secondChar
                    });
                }


                // push blocked character back
                maxHeap.push({
                    count,
                    ch
                });
            }

            else {

                // safe to use
                ans += ch;

                count--;


                // still remaining?
                if(count > 0) {

                    maxHeap.push({
                        count,
                        ch
                    });
                }
            }
        }

        return ans;
    }
};
