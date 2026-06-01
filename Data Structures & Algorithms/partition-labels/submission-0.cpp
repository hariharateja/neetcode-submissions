class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Record the last occurrence of each character
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0;
        int end = 0;
        
        // Step 2: Walk through the string and make greedy cuts
        for (int i = 0; i < s.length(); i++) {
            // Update the end of the current partition to the furthest required position
            end = max(end, lastIndex[s[i] - 'a']);
            
            // If we have reached the boundary of our partition
            if (i == end) {
                result.push_back(end - start + 1); // Record the size
                start = i + 1;                     // Move start to the next partition
            }
        }
        
        return result;
    }
};
