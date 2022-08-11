class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> table(n, vector<bool>(n, false));
        
        int max_len = 1, start_idx = 0;
        
        // preprocess
        for(auto i = 0; i < n; ++i) table[i][i] = true;
        for(auto i = 0; i < n - 1; ++i) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true;
                max_len = 2;
                start_idx = i; 
            }
        }
        
	// DP
        for(auto len = 3; len <= n; ++len) {
            for(auto i = 0; (i + len - 1) < n; ++i) {
                auto j = i + len - 1;
                if(s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    max_len = len;
                    start_idx = i;
                }
            }
        }
        
        return s.substr(start_idx, max_len);
    }
};
