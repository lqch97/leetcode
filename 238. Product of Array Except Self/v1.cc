class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto n = nums.size();
        vector<int> prefix(n), suffix(n);
        
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(auto i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[n-1-i] = suffix[n-i] * nums[n-1-i];
        }
        
        nums[0] = suffix[1];
        nums[n-1] = prefix[n-2];
        for(auto i = 1; i < n-1; ++i) {
            nums[i] = prefix[i-1] * suffix[i+1];
        }
        
        return nums;
    }
};
