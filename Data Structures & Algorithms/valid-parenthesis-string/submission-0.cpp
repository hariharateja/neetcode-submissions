class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { // c == '*'
                leftMin--; // Option 1: Treat as ')'
                leftMax++; // Option 2: Treat as '('
            }
            
            // If max possible open braces is negative, there are too many ')'
            if (leftMax < 0) return false;
            
            // Min open braces cannot be negative; reset to 0 (treat extra '*' as "")
            if (leftMin < 0) leftMin = 0;
        }
        
        // The string is valid if we can perfectly end with 0 open braces
        return leftMin == 0;
    }
};