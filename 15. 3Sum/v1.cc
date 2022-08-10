class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto i = 0; i < n; ++i) m[nums[i]] = i;
        
        vector<vector<int>> res;
        for(auto i = 0; i < n - 2; ++i) {
            for(auto j = i + 1; j < n - 1; ++j) {
                auto x = -nums[i] - nums[j];
                if(m.count(x) && m[x] > j) 
                    res.push_back({nums[i], nums[j], x});
                j = m[nums[j]];
            }
            i = m[nums[i]];
        }
        
        return res;
    }
};
