class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> output;

        // Sort the input array in descending order
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        // Iterate through the sorted array
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int threeSum = nums[i] + nums[j] + nums[k];
                if (threeSum < 0) k--;                
                else if (threeSum > 0) j++;
                else
                {
                    output.push_back({nums[k], nums[j], nums[i]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return output;
    }
};
