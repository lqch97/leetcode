class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1, j;
        
        for( ; i >= 1 && nums[i-1] >= nums[i]; --i); // nothing
        
        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        --i;
        for(j = i+1; j < n-1 && nums[j + 1] > nums[i]; ++j); // nothing
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
