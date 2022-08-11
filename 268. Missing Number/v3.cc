class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(auto i = 0; i < n; ++i) {
            res = res ^ i ^ nums[i];
        }
        return res ^ n;
    }
};
