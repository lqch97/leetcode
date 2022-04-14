class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        
        vector<int> table(n + 1, 0);
        
        table[0] = table[1] = 1;
        
        for(auto tree_size = 2; tree_size <=n; ++tree_size) {
            for(auto n_left = 0; n_left <= tree_size - 1; ++n_left) {
                table[tree_size] += table[n_left] * table[tree_size - n_left -1];
            }
        }
        
        return table[n];
    }
};
