class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;

        for (auto& c : s) sMap[c]++;
        for (auto& c : t) tMap[c]++;

        if (sMap.size() != tMap.size()) return false;

        for (auto& k : sMap)
        {
            if (k.second != tMap[k.first]) return false;
        }
        return true;

        // return (sMap == tMap); // Available for C++20 and newer
    }
};
