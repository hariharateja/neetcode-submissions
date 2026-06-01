class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Base math check
        if (hand.size() % groupSize != 0) return false;
        
        // Count frequencies in an ordered map (automatically sorts keys)
        map<int, int> cardCounts;
        for (int card : hand) {
            cardCounts[card]++;
        }
        
        // Iterate through the sorted cards
        for (auto it = cardCounts.begin(); it != cardCounts.end(); it++) {
            int currentCard = it->first;
            int count = it->second;
            
            // If we have cards of this value left to process
            if (count > 0) {
                // We need to form 'count' number of groups starting with currentCard
                for (int i = 0; i < groupSize; i++) {
                    int nextCard = currentCard + i;
                    
                    // If the required consecutive card doesn't exist or is used up
                    if (cardCounts[nextCard] < count) {
                        return false;
                    }
                    
                    // Deduct the cards used
                    cardCounts[nextCard] -= count;
                }
            }
        }
        
        return true;
    }
};