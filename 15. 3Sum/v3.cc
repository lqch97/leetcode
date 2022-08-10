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
                if(two_sum < -x) ++l;
                else if(two_sum > -x) --r;
                else { 
                    res.push_back({x, nums[l], nums[r]});
                    while(l < r && nums[l+1] == nums[l]) ++l;
                    while(l < r && nums[r-1] == nums[r]) --r;
                    ++l; --r;
                }
            }

            while(i < n-3 && nums[i+1] == nums[i]) ++i;
        }
        
        return res;
    }
};
