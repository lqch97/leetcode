class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto slow = nums[0], fast = nums[nums[0]];
        while(fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        auto head = nums[0];
        slow = nums[slow];
        while(head != slow) {
            head = nums[head];
            slow = nums[slow];
        }
        
        return head;
    }
};
