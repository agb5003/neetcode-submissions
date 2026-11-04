class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> differenceMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (differenceMap.count(nums[i]) == 0)
            {
                differenceMap[difference] = i;
            } else {
                return {differenceMap[nums[i]], i};
            }
        }

        return {0, 0};
    }
};
