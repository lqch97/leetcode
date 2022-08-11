class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;
        return sum - reduce(nums.begin(), nums.end());
    }
};
