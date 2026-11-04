class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        // Convert vector into set to order and discard duplicates
        std::set<int> numSet(nums.begin(), nums.end());
        // Convert back into an std::vector to enable iteration
        std::vector<int> organizedNums(numSet.begin(), numSet.end());

        int longestLength = 1;
        int currentSequenceLength = 1;
        for (int i = 1; i < organizedNums.size(); i++)
        {
            if (organizedNums[i-1] != organizedNums[i] - 1)
            {
                // Start of new sequence
                // Update longest length if previous sequence is new longest
                if (currentSequenceLength > longestLength) longestLength = currentSequenceLength;
                // Reset sequence length to 1
                currentSequenceLength = 1;
            } else {
                currentSequenceLength++;
            }
        }
        // Catch the edge case where longest sequence ends in the last element of organizedNums
        if (currentSequenceLength > longestLength) longestLength = currentSequenceLength;

        return longestLength;  
    }
};
