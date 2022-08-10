class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> res;
        
        for(auto i = 0; i < n - 2; ++i) {
            auto x = nums[i];
            auto l = i + 1, r = n - 1;
            while(l < r) { 
                auto two_sum = nums[l] + nums[r];
                if(two_sum == -x) res.push_back({x, nums[l++], nums[r--]});
                else if(two_sum < -x) ++l;
                else --r;
            }
            while(i < n-3 && nums[i + 1] == nums[i]) ++i;
        }
        
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;
    }
};
