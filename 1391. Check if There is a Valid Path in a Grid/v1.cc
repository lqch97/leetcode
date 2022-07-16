class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> used(m, vector(n, false));
        
        vector<vector<pair<int, int>>> moves {
            { {0, -1}, {0, 1} }, // 1
            { {-1, 0}, {1, 0} },
            { {0, -1}, {1, 0} }, // 3
            { {0, 1}, {1, 0} },
            { {0, -1}, {-1, 0} }, // 5
            { {0, 1}, {-1, 0} },
        };
        
        stack<pair<int, int>> s;
        used[0][0] = true;
        s.push({0, 0});
        
        while(!s.empty()) {
            auto p = s.top(); s.pop();
            auto i = p.first, j = p.second;
            if(i == m-1 && j == n-1) return true;
            for(auto move: moves[ grid[i][j] - 1 ]) {
                auto newi = i + move.first, newj = j + move.second;
                if(0 <= newi && newi < m && 0 <= newj && newj < n && used[newi][newj] == false) {
                    auto& move_back = moves[ grid[newi][new] - 1 ];
                    auto res = find_if(move_back.begin(), move_back.end(), [=](pair<int, int> m) {
                        return pair{newi + m.first, newj + m.second} == p;
                    });
                    if(res != move_back.end()) {
                        used[newi][newj] = true;
                        s.push({newi, newj});
                    }
                }
            }
        }
        
        return false;
    }
};
