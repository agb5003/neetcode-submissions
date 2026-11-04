// Naive

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check each row for duplicates
        for (const auto& row : board) {
            std::unordered_set<char> seenChars;
            for (const auto& curChar : row) {
                if (curChar == '.') continue;
                if (!seenChars.insert(curChar).second) {
                    return false;
                }
            }
        }

        // Check each column for duplicates
        for (int i = 0; i < board[0].size(); i++) {
            std::unordered_set<char> seenChars;
            for (const auto& row : board) {
                char curChar = row[i];
                if (curChar == '.') continue;
                if (!seenChars.insert(curChar).second) {
                    return false;
                }
            }
        }

        // Check each sub-box for duplicates
        for (int i = 0; i < board[0].size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                std::unordered_set<char> seenChars;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char curChar = board[i+k][j+l];
                        if (curChar == '.') continue;
                        if (!seenChars.insert(curChar).second) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
