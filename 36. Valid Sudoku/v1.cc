class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto i = 0; i < 9; ++i) if(!checkRow(board, i)) return false;
        for(auto j = 0; j < 9; ++j) if(!checkCol(board, j)) return false;
        
        for(auto i = 0; i < 9; i += 3)
            for(auto j = 0; j < 9; j += 3) 
                if(!checkBox(board, i, j)) return false;
        
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int x, int y) {
        unordered_set<char> m;
        for(auto i = 0; i <= 2; ++i) {
            for(auto j = 0; j <= 2; ++j) {
                auto num = board[x+i][y+j];
                if(num != '.') {
                    auto it = m.find(num);
                    if(it != m.end()) return false;
                    m.insert(num);
                }
            }
        }
        return true;
    }
    
    bool checkRow(vector<vector<char>>& board, int x) {
        unordered_set<char> m;
        for(auto j = 0; j < 9; ++j) {
            autonum = board[x][j];
            if(num != '.') {
                auto it = m.find(num);
                if(it != m.end()) return false;
                m.insert(num);
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int y) {
        unordered_set<char> m;
        for(auto i = 0; i < 9; ++i) {
            auto num = board[i][y];
            if(num != '.') {
                auto it = m.find(num);
                if(it != m.end()) return false;
                m.insert(num);
            }
        }
        return true;
    }
}; 
