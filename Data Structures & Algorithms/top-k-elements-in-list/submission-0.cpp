#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> uniqueElements;
        for (int num : nums) {
            uniqueElements[num]++;
        }

        vector<pair<int, int>> freqList(uniqueElements.begin(), uniqueElements.end());

        // Sort the vector based on frequency in descending order.
        sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;  // Compare frequencies
        });

        // Extract the top k frequent numbers.
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].first);  // Push the number to the result vector
        }

        return result;
    }
};
