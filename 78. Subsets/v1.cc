class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return util(nums, nums.size() - 1);
    }
    
    vector<vector<int>> util(vector<int>& nums, int last) {
        if(last == 0) {
            return vector<vector<int>> {vector<int>(), vector<int> {nums[last]}};
        }
        
        auto sub_prob = util(nums, last - 1);
        vector<vector<int>> infer;
        auto num = nums[last];
        
        for(auto s: sub_prob) {
            s.push_back(num);
            infer.push_back(s);
        }
        
        sub_prob.insert(sub_prob.end(), infer.begin(), infer.end());
        return sub_prob;
    }
};
