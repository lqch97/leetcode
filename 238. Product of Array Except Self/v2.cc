/**
 * O(1) space solution
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto n = nums.size();
        vector<int> res(n);
        
        auto prefix = 1;
        for(int i = 0; i < n; ++i) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        
        auto suffix = 1;
        for(int i = n-1; i >= 0; --i) {
            res[i] = res[i] * suffix;
            suffix *= nums[i];
        }
        
        return res;
    }
};
