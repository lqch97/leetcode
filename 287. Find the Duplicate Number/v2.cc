class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;
        while(lo < hi) {
            auto mid = (lo + hi) / 2;
            auto cnt = count_if(nums.begin(), nums.end(), [=](auto x) { return x <= mid; });
            if(cnt <= mid) lo = mid + 1;
            else hi = mid;
        }
        return hi;
    }
};
