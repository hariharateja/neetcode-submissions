class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Flags to track if we found the exact match for x, y, and z safely
        bool foundX = false;
        bool foundY = false;
        bool foundZ = false;
        
        int targetX = target[0], targetY = target[1], targetZ = target[2];
        
        for (const auto& triplet : triplets) {
            // STEP 1: Filter out any triplet that overshoots the target
            if (triplet[0] > targetX || triplet[1] > targetY || triplet[2] > targetZ) {
                continue; // Skip this triplet entirely
            }
            
            // STEP 2: If it's safe, see if it provides any of the exact numbers we need
            if (triplet[0] == targetX) foundX = true;
            if (triplet[1] == targetY) foundY = true;
            if (triplet[2] == targetZ) foundZ = true;
            
            // Optimization: If we found all three components, we can stop early
            if (foundX && foundY && foundZ) {
                return true;
            }
        }
        
        // Return true only if we hit all three targets using valid safe triplets
        return foundX && foundY && foundZ;
    }
};