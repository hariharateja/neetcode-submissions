class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Already at the end
        
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // Loop up to n - 1 because we don't need to jump once we land on the last index
        for (int i = 0; i < n - 1; i++) {
            // Keep track of the absolute maximum reach possible from the current level
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of our current jump's reach
            if (i == currentEnd) {
                jumps++;            // We must take another jump
                currentEnd = farthest; // Update the boundary for the next jump level
                
                // If the next boundary already reaches or clears the end, we can stop early
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};