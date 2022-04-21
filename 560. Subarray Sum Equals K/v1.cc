class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(nums);
        
        for(auto i = 1; i < n; ++i) {
            prefix[i] += prefix[i-1];
        }
        
        int res = 0;
        for(auto i = 0; i < n; ++i) {
            if(prefix[i] == k) ++res;
            for(auto j = i+1; j < n; ++j) {
                if(prefix[j] - prefix[i] == k) ++res;
            }
        }
        
        return res;
    }
};
