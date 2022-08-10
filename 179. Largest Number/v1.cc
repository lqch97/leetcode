class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s_nums;
        for(auto x: nums) s_nums.push_back(to_string(x));
        sort(s_nums.begin(), s_nums.end(), [](auto x, auto y) {
            return (x+y) > (y+x);
        });
        return s_nums[0] == "0" ? 
            "0" : reduce(s_nums.begin(), s_nums.end());
    }
};

