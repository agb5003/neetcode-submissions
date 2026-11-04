#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string a, std::string b) {
        if (a.size() != b.size()) { return false; }

        // std::sort does not return a sorted container.
        // newContainer = std::sort(...) does not work. It works in place.
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        return a == b;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> output;
        while (strs.size() > 0) {
            output.push_back(std::vector<std::string> {strs[0]}); // Copy element at the start into output
            strs.erase(strs.begin()); // Erase element at the start of strs
            // Iterate through rest of strs
            for (auto comparedIterator = strs.begin(); comparedIterator != strs.end();) {
                if (isAnagram(*comparedIterator, output.back()[0])) {
                    output.back().push_back(*comparedIterator);
                    strs.erase(comparedIterator);
                } else {
                    comparedIterator++;
                }
            }
        }
        return output;
    }
};
