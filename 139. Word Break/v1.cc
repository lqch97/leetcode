class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        vector<bool> table(n);
        
        table[0] = (dict.find(s.substr(0, 1)) != dict.end());
        for(auto i = 1; i < n; ++i) {
            if(dict.find(s.substr(0, i - 0 + 1)) != dict.end()) {
                table[i] = true;
                continue;
            }
            
            for(auto j = 1; j <= i; ++j) {
                if(dict.find(s.substr(j, i - j + 1)) != dict.end() && table[j-1] == true) {
                    table[i] = true;
                    break;
                }
            }
        }
        
        return table[n-1];
    }
};
