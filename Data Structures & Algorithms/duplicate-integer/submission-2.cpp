class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set numSet(nums.begin(), nums.end());

        return (nums.size() != numSet.size());
    }
};