class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int>ans;
        int n = nums.size();
        ans.reserve(2 * n);

        for(auto& num : nums){
            ans.push_back(num);
        }

        for(auto& num : nums){
            ans.push_back(num);
        }
        return ans;
    }
};