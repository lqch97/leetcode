/*
 * O(nlgn) + O(n) solution
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> s;
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        for(auto i = 1; i < intervals.size(); ++i) {
            auto curr = intervals[i];
            auto prev = res.back();
            
            if(prev[1] >= curr[0]) res.back()[1] = max(curr[1], prev[1]);
            else res.push_back(curr);
        }
        
        return res;
    }
};
