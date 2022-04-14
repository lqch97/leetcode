class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        constexpr int bit_len = 10;
        auto n = nums.size();
        vector<vector<int>> ret;
        
        for(auto i = 0; i < pow(2, n); ++i) {
            bitset<bit_len> bs(i);
            vector<int> curr;
            for(auto j = 0; j < n; ++j) {
                if(bs[j]) curr.push_back(nums[j]);
            }
            ret.push_back(curr);
        }
        
        return ret;
    }
};
