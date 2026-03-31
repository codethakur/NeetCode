class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int>hasElements;

        for(auto& num : nums)
        {
            if (hasElements.count(num)) {
                return true;
            }
                hasElements.insert(num);
        }
        return false;
    }
};