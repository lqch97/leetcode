class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),
            n = matrix[0].size();
        
        vector<bool> clr_row(m, false), clr_col(n, false);
        
        for(auto i = 0; i < m; ++i)
            for(auto j = 0; j < n; ++j)
                if(matrix[i][j] == 0) {
                    clr_row[i] = true;
                    clr_col[j] = true;
                }
        
        for(auto i = 0; i < m; ++i)
            for(auto j = 0; j < n; ++j)
                if(clr_row[i] || clr_col[j])
                    matrix[i][j] = 0;
        
    }
};
