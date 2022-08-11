class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        int table[n1+1][n2+1];
        
        for(auto i = 0; i <= n1; ++i) table[i][0] = 0;
        for(auto j = 0; j <= n2; ++j) table[0][j] = 0;
        
        for(auto i = 1; i <= n1; ++i) {
            for(auto j = 1; j <= n2; ++j) {
                table[i][j] = (text1[i-1] == text2[j-1]) ? 
                    table[i-1][j-1] + 1 : 
                    max(table[i-1][j], table[i][j-1]);
            }
        }
        
        return table[n1][n2];
    }
};
