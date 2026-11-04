class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> products(nums.size(), 1);

        products[0] = 1;
        // Fill with product of elements to the left of products[i]
        for (int i = 1; i < nums.size(); i++)
        {
            products[i] = products[i-1] * nums[i-1];   
        }
        // Multiply prefix products with postfix products
        int postfixProduct = 1;
        // Since there are no elements to the right of the last one, start with second to last
        for (int i = nums.size()-2; i >= 0; i--)
        {
            postfixProduct *= nums[i+1];
            products[i] *= postfixProduct;
        }

        return products;
    }
};
