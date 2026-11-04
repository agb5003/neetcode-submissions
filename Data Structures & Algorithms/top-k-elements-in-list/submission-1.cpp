#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> uniqueElements;
        std::vector<int> result;

        for (int num : nums) {
            // Check if current element is unique or if it's already in the tracker vector
            auto it = std::find_if(uniqueElements.begin(), uniqueElements.end(), [num](const auto& pair) {
                return pair.first == num;
                });

            if (it != uniqueElements.end()) {
                it->second++;
            }
            else {
                uniqueElements.push_back({ num, 1 });
            }
        }

        // Sort occurences of unique elements
        std::sort(uniqueElements.begin(), uniqueElements.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++) {
            result.push_back(uniqueElements[i].first);
        }

        return result;
    }
};
