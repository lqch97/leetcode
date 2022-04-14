/*
 * v2. O(n) space solution
 * use two length n vector instead of whole table
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row_above(n), row_below(n);
        
        for(auto i = 0; i < n; ++i) row_above[i] = 1;
        row_below[0] = 1;
        
        for(auto row = 1; row < m; ++row) {
            for(auto j = 1; j < n; ++j) {
                row_below[j] = row_above[j] + row_below[j-1];
            }
            
            swap(row_above, row_below);
        }
        
        
        return row_above[n-1];
    }
};
