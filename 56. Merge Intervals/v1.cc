class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = 10001;
        vector<int> start(len, 0), end(len, 0);
        vector<vector<int>> ret;
        
        for(auto i: intervals) {
            start[i[0]] += 1;
            end[i[1]] += 1;
        }
        
        int count = 0, left = -1;
        for(auto i = 0; i < len; ++i) {
            count += start[i];
            if(left == -1 && count > 0) {
                left = i;
            }
            
            count -= end[i];
            if(left != -1 && count == 0) {
                ret.push_back(vector<int>{left, i});
                left = -1;
            }
        }
        
        return ret;
    }
};
