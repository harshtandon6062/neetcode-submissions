class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, target, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int> & cur, int target, int i){
        if(i >= nums.size() || target < 0) return;
        if(target == 0){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        helper(nums, res, cur, target - nums[i], i);
        cur.pop_back();
        helper(nums, res, cur, target, i+1);
    }
};
