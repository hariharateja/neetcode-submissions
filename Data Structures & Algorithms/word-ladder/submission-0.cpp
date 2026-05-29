class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word , steps] = q.front();
            q.pop();
            if (word == endWord) return steps;
            for(int i = 0;i < word.length(); ++i){
                char originalchar = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if (dict.find(word) != dict.end()) {
                        dict.erase(word); // Erase it so we don't visit it again (prevents infinite loops)
                        q.push({word, steps + 1});
                    }
                }
                word[i] = originalchar;
            }
        }
        return 0;
    }
};
