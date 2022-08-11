class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            auto mid = (l + r) / 2;
            auto nl = nums[l], nr = nums[r], nm = nums[mid];
                        
            if(nl < nr) {
                if(target == nm) return mid;
                if(target < nm) r = mid - 1;
                else l = mid + 1;
            } 
            else {
                if(target == nm) return mid;
                if(target == nr) return r;
                
                if( (nm > nr && target < nr) 
                   || (nm > nr && target > nm) 
                   || (nm < target && target < nr) ) 
                l = mid + 1;
                else r = mid - 1;
            }            
        }
        return -1;
    }
};
