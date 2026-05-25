

class Solution {
private:
    // A constant array to map index to button characters.
    // Index 0 maps to "", Index 2 maps to "abc", etc.
    const std::vector<std::string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int index, const std::string& digits, std::string& currentPath, std::vector<std::string>& result) {
        // BASE CASE: If the current string matches the size of digits, 
        // we've combined a letter from every single digit requested!
        if (index == digits.length()) {
            result.push_back(currentPath);
            return;
        }

        // 1. Find the letters corresponding to the current digit
        int digitButton = digits[index] - '0'; // Convert char digit (e.g. '3') to int (3)
        std::string letters = keypad[digitButton];

        // 2. Loop through all the available letters for this button
        for (int i = 0; i < letters.length(); i++) {
            // Choose
            currentPath.push_back(letters[i]);

            // Explore: Move to the NEXT digit in the input string (index + 1)
            backtrack(index + 1, digits, currentPath, result);

            // Un-choose (Backtrack)
            currentPath.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Edge case: If the input is empty, return an empty result list
        if (digits.empty()) {
            return result;
        }

        std::string currentPath = "";
        backtrack(0, digits, currentPath, result);
        return result;
    }
};