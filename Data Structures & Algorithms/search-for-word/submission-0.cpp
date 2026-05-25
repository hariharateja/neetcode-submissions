#include <vector>
#include <string>

class Solution {
private:
    bool backtrack(int r, int c, int index, std::vector<std::vector<char>>& board, const std::string& word) {
        // BASE CASE 1: If we have matched all characters in the word, we found it!
        if (index == word.length()) {
            return true;
        }

        // BASE CASE 2: Out of bounds check or character mismatch
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // 1. CHOOSE: Save the current character and mark this cell as visited using a temporary placeholder
        char temp = board[r][c];
        board[r][c] = '#'; // Mark as visited so we don't reuse it in this path

        // 2. EXPLORE: Check all 4 neighboring directions (Up, Down, Left, Right)
        bool found = backtrack(r + 1, c, index + 1, board, word) || // Down
                     backtrack(r - 1, c, index + 1, board, word) || // Up
                     backtrack(r, c + 1, index + 1, board, word) || // Right
                     backtrack(r, c - 1, index + 1, board, word);   // Left

        // 3. UN-CHOOSE (Backtrack): Restore the original character so other paths can use it
        board[r][c] = temp;

        return found;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Scan the entire grid to find where the first letter matches
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    // Start backtracking from this matching cell
                    if (backtrack(r, c, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};