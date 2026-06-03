class Solution {
        bool isTurbulent(vector<int>& arr, int start, int end)
        {
            int len = end - start + 1;

            if(len == 1)
                return true;

            if(len == 2)
                return arr[start] != arr[end];

            for(int i = start + 1 ; i<end; i++)
            {
                long long left =(long long)(arr[i] - arr[i - 1]);
                long long right = (long long)(arr[i + 1] - arr[i]);

                if(left == 0|| right == 0) return false;
                if(left > 0 && right>0 || left<0 && right<0) return false;

            }
            return true;
        }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;

        for(int i = 0; i<arr.size(); i++)
        {
            for(int j = 1; j<arr.size(); j++)
            {
                if(isTurbulent(arr, i, j))
                {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
