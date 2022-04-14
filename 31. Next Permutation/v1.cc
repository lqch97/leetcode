class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        utility(nums, 0);
    }
    
    // return false if there is no next permutation in range [index ... end]
    // side effect: next permutation in range [index ... end]
    bool utility(vector<int>& nums, int index) {
        int n = nums.size();
        
        // basis case
        if(index == n - 1) {
            return false;
        }
        
        // if next perm from nums[index + 1] exist
        // simplely return num[index] + nextPerm(num[index + 1])
        if(utility(nums, index + 1)) return true;
        
        // if no number in nums[index+1 ... end] larger than nums[index]
        if(nums[n-1] <= nums[index]) {
            int temp = nums[index];
            for(int i = index + 1; i < n; ++i) {
                nums[i-1] = nums[i];
            }
            nums[n-1] = temp;
            return false;
        } 
        
        // if there is a number larger than nums[index] 
        // select the smalles one and swap(num[index], the selected one)
        int pivot = nums[index];
        for(int i = index + 1; i < n; ++i) {
            if(nums[i] > pivot) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        return true;
    }
};
