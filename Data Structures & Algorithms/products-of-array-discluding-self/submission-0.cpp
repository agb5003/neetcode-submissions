class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> products;
        for (auto& i : nums)
        {
            products.push_back(1);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    products[i] *= nums[j];
                }
            }
        }

        return products;
    }
};
