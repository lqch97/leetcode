// Extra space O(1) solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),
            n = matrix[0].size();
        
        bool clr_row0 = false, clr_col0 = false;
        
        for(auto i = 0; i < m; ++i)
            if(matrix[i][0] == 0) clr_col0 = true;
        
        for(auto j = 0; j < n; ++j)
            if(matrix[0][j] == 0) clr_row0 = true;
        
        for(auto i = 1; i < m; ++i)
            for(auto j = 1; j < n; ++j)
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        
        for(auto i = 1; i < m; ++i)
            for(auto j = 1; j < n; ++j)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if(clr_row0)
            for(auto j = 0; j < n; ++j) matrix[0][j] = 0;
        
        if(clr_col0)
            for(auto i = 0; i < m; ++i) matrix[i][0] = 0;
            
    }
};
