class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> v(nums.size()+1, false);
        for(auto x: nums) v[x] = true;
        return distance(v.begin(), find(v.begin(), v.end(), false));
    }
};
