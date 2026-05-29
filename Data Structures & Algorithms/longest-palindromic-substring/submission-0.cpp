#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to expand outwards and return the length of the palindrome
    int expandAroundCenter(const std::string& s, int left, int right) {
        // Expand as long as pointers are in bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the valid palindrome found
        // (right - left - 1) because the while loop stops *after* pointers go 1 step too far
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0; // To keep track of the starting index of our best palindrome
        int maxLength = 0; // To keep track of the maximum length found

        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindrome (e.g., "aba", center is i)
            int len1 = expandAroundCenter(s, i, i);
            
            // Case 2: Even length palindrome (e.g., "abba", center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length found at this center
            int len = std::max(len1, len2);

            // If we found a longer palindrome than our previous best, update our trackers
            if (len > maxLength) {
                maxLength = len;
                // Formula to find the starting index based on the center i and the length
                start = i - (len - 1) / 2;
            }
        }

        // Return the actual substring using start position and length
        return s.substr(start, maxLength);
    }
};