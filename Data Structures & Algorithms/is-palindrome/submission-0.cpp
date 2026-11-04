#include <cctype>
#include <string>
#include <sstream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string noSpace;
        std::string flipped;
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];
            if (std::isalnum(currentChar)) {
                noSpace += tolower(s[i]);
            }
        }
        
        for (int i = 0; i < noSpace.length(); i++) {
            flipped += noSpace[noSpace.length()-1-i];
        }

        if (flipped == noSpace) {
            return true;
        }
        return false;
    }
};
