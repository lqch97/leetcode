/**
 * @file main.cc
 * @author lqch
 * @brief O(n^2 lg(n)) solution
 * @version 0.1
 * @date 2022-03-26
 * 
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> output;
        vector<vector<int>> ret;

        for(int i=2; i<nums.size(); ++i) {
            if(it == used.end()) {
                auto v = twoSum(nums, i-1, 0-nums[i]);
                if(v.size() != 0) {
                    for(auto x: v) {
                        x.push_back(nums[i]);
                        ret.push_back(x);
                    }
                }
            }
        }

        return ret;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int last, int sum) {
        set<int> m;
        vector<vector<int>> ret;
        
        for(int i=0; i<= last; ++i) {
            auto x = nums[i], y = sum - nums[i];

            auto it_y = m.find(y);
            
            // why it_y first ?
            // to prevent the case when sum = 2x = 2y
            // then x is inserted and found again
            if(it_y != m.end()) { // y not exist
                ret.push_back(vector<int>{x, y});
            }

            auto it_x = m.find(x);
            if(it_x == m.end()) { // x not exist
                m.insert(x);
            }
        }
            
        return ret;
    }
};
