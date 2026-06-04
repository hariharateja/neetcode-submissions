class CountSquares {
private:
    // mapX[x][y] = count of points at (x, y)
    std::unordered_map<int, std::unordered_map<int, int>> mapX;
    // mapY[y][x] = count of points at (x, y)
    std::unordered_map<int, std::unordered_map<int, int>> mapY;

public:
    CountSquares() {}
    
    void add(std::vector<int> point) {
        int x = point[0];
        int y = point[1];
        mapX[x][y]++;
        mapY[y][x]++;
    }
    
    int count(std::vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int totalSquares = 0;
        
        // If there are no points sharing the same X or Y, no square can exist
        if (mapX.find(x1) == mapX.end() || mapY.find(y1) == mapY.end()) {
            return 0;
        }
        
        // Iterate through all vertical neighbors P3(x1, y2)
        for (const auto& [y2, freqP3] : mapX[x1]) {
            if (y2 == y1) continue; 
            int sideLengthY = std::abs(y1 - y2);
            
            // Iterate through all horizontal neighbors P2(x2, y1)
            for (const auto& [x2, freqP2] : mapY[y1]) {
                if (x2 == x1) continue;
                int sideLengthX = std::abs(x1 - x2);
                
                // If it's a valid square (orthogonal side lengths match)
                if (sideLengthX == sideLengthY) {
                    // Check if the closing corner P4(x2, y2) exists
                    if (mapX[x2].find(y2) != mapX[x2].end()) {
                        int freqP4 = mapX[x2][y2];
                        totalSquares += freqP3 * freqP2 * freqP4;
                    }
                }
            }
        }
        
        return totalSquares;
    }
};
