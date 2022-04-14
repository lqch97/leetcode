/*
 * one pass solution
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> r(9), c(9);
        vector<vector<set<char>>> box(3, vector<set<char>>(3));
        for(auto i = 0; i < 9; ++i) {
            for(auto j = 0; j < 9; ++j) {
                auto num = board[i][j];
                if(num == '.') continue;
                
                if(r[i].find(num) != r[i].end()) return false;
                r[i].insert(num);
                
                if(c[j].find(num) != c[j].end()) return false;
                c[j].insert(num);
                
                if(box[i/3][j/3].find(num) != box[i/3][j/3].end()) return false;
                box[i/3][j/3].insert(num);
            }
        }
        
        return true;
    }
};
