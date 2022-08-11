class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_len = nums[0];
        
        for(auto i = 1; i < n; ++i) {
            if(max_len <= 0) return false;
            max_len = max(max_len - 1, nums[i]);
        }
        
        return true;
    }
};
