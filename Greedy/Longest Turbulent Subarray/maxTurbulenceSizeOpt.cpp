class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
       int left = 0, right = 1, ans = 1;

       string prev = "";
       while(right<arr.size())
       {
            if(arr[right-1] >arr[right] && prev != ">")
            {
                ans = max(ans, right-left+1);
                right++;
                prev = ">";
            }
            else if (arr[right-1]<arr[right] && prev != "<")
            {
                ans = max(ans, right-left+1);
                right++;
                prev = "<";
            }else
            {
                right = (arr[right] == arr[right-1]) ? right + 1: right;
                left = right-1;
                prev = "";
            }
       } 
       return ans;
    }
};
