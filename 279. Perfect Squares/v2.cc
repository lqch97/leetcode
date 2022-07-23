class Solution {
public:
    int numSquares(int n) {
        vector<int> table{0};
        for(auto i = 1; i <= n; ++i) {
            auto min_val = numeric_limits<int>::max();
            for(auto sqr = 1; sqr*sqr <= i; ++sqr) {
                min_val = min(min_val, table[i - sqr*sqr] + 1);
            }
            table.push_back(min_val);
        }
        return table.back();
    }
};
