class Solution {
public:
    int numSquares(int n) {
        
        vector<int> squares;
        for(auto i = 1; i * i <= n; ++i) squares.push_back(i * i);
        
        vector<int> table(n+1, numeric_limits<int>::max() - 1);
        table[0] = 0;
        
        for(auto i = 0; i <= n; ++i) {
            for(auto sq: squares) {
                if(sq > i) break;
                table[i] = min(table[i], table[i-sq] + 1);
            }
        }
        
        return table[n];
    }
};
