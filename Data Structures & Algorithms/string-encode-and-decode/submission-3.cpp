#include <cstring>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded;
        for (auto& s : strs)
        {
            encoded.append(s);
            encoded.append("<BREAK>");        
        }
        return encoded;
    }

    vector<string> decode(string str) {
        std::vector<std::string> decoded;
        size_t breakpos = str.find("<BREAK>");
        while (breakpos != std::string::npos)
        {
            std::string word;
            word.append(str, 0, breakpos);
            str.erase(0, breakpos+std::strlen("<BREAK>"));
            std::cout << word << std::endl;
            decoded.push_back(word);

            breakpos = str.find("<BREAK>");
        }
        return decoded;
    }
};
