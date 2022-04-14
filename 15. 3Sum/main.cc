/**
 * @author lqch
 * @brief O(n^2 lg(n)) solution
 * @version 0.1
 * @date 2022-03-26
 * 
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, set<pair<int, int>>> m;
        vector<vector<int>> ret;
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = i+1; j < nums.size(); ++j) {
                auto x = nums[i], y = nums[j];
                auto xy = (x < y) ? pair<int, int>(x, y): pair<int, int>(y, x); 

                auto it = m.find(x + y);
                if(it == m.end()) 
                    it->second.insert(xy);
                else 
                    auto temp_set = set<pair<int, int>> {xy};
                    // m.insert(pair<int, set<pair<int, int>> { x+y, set<pair<int, int>>{xy} });
                    m.insert(pair<int, set<pair<int, int>(x+y, temp_set));
            }
        }

        for(auto x: nums) {
            auto y = 0 - x;
            auto it = m.find(y);
            if(it == m.end()) {
                for(auto one_pair: it->second) {
                    ret.push_back(vector<int> {one_pair.first, one_pair.second, y});
                }
            }
        }
        return ret;
    }
};