/*
 * time: O(n)
 * concept: for all j, push all prefixSum(i) where i < j to map,
 * then check prefixSum(j) - k in map or not.
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> prefix(nums);
        map<int, int> m{{0, 1}};
        
        for(auto i = 1; i < n; ++i) {
            prefix[i] += prefix[i-1];
        }
        
        for(auto i = 0; i < n; ++i) {
            auto x = prefix[i];
            res += m[x - k];
            ++m[x];
        }
        
        return res;
    }
};
