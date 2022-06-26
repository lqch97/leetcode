class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> table(n + 1, 0);
        table[n] = 1;
        for(int i = n-1; i >= 0; --i) {
            int val = s[i] - '0';
            int res = 0;
            if (1 <= val && val <= 26) {
                res += table[i + 1];
            }
            if (i+2 <= n) {
                val = val * 10 + s[i + 1] -'0';
                if (1 <= val && val <= 26)
                    res += table[i + 2];
            }
            if (s[i] == '0') res = 0;
            table[i] = res;
        }
        return table[0];
    }
};
