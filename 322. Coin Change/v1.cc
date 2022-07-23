class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        auto MAX = numeric_limits<int>::max() - amount;
        vector<int> table(amount + 1, MAX);
        
        sort(coins.begin(), coins.end());
        
        table[0] = 0;
        for(auto i = 1; i <= amount; ++i) {
            for(auto c: coins) {
                if(i - c >= 0) table[i] = min(table[i], table[i - c] + 1);
            }
        }
        
        return table[amount] >= MAX ? -1 : table[amount];
        
    }
};
