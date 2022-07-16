// divide and conquer solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return util(nums, 0, nums.size() - 1);
    }
    
    int util(vector<int>& nums, int start, int end) {
        if(end == start) return nums[start];
        auto mid = (start + end) / 2;
        auto left = util(nums, start, mid),
             right = util(nums, mid + 1, end);
        
        // find the largest sum containing nums[mid] nums[mid+1]
        // left hand side
        auto max_left = nums[mid];
        auto curr = nums[mid];
        for(auto i = mid - 1; i >= start; --i) {
            curr += nums[i];
            if(curr > max_left) max_left = curr;
        }
        
        // right hand side
        auto max_right = nums[mid + 1];
        curr = nums[mid + 1];
        for(auto i = mid + 2; i <= end; ++i) {
            curr += nums[i];
            if(curr > max_right) max_right = curr;
        }
        
        auto res = max_left + max_right;
        
        return max( left, max(right, res) );
    }
};
