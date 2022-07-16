class Solution {
public:
    using Board = vector<vector<int>>;
    
    int slidingPuzzle(vector<vector<int>>& board) {
        
        Board Final = {
            {1, 2, 3}, {4, 5, 0}
        };
        
        queue< pair<Board, int> > q;
        set<Board> used;
        q.push({board, 0});
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            if(curr.first == Final) return curr.second;
            auto candidates = branch(curr.first);
            for(auto c: candidates) {
                if(used.find(c) == used.end()) {
                    used.insert(c);
                    q.push({c, curr.second + 1});
                }
            }
        }
        
        return -1;
    }
    
    vector<Board> branch(Board board) {
        vector<Board> res;
        auto p = zeroAt(board);
        auto p1 = p.first, p2 = p.second;
        vector<pair<int, int>> indices{
            {p1+1, p2}, {p1-1, p2}, {p1, p2+1}, {p1, p2-1}
        };
        
        for(auto : indices) {
            auto i1 = i.first, i2 = i.second;
            if(i1 >= 0 && i1 < 2 && i2 >= 0 && i2 <3) {
                auto new_board = board;
                swap(new_board[p1][p2], new_board[i1][i2]);
                res.push_back(new_board);
            }
        }
        
        return res;
    }
    
    pair<int, int> zeroAt(Board& board) {
        for(auto i = 0; i < 2; ++i) {
            for(auto j = 0; j < 3; ++j) {
                if(board[i][j] == 0) return {i, j};
            }
        }
        return {-1, -1};
    }
};
