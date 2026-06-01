class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int target, int i){
        if(target == 0){
            res.push_back(subset);
            return;
        } 
        if(i >= nums.size() || nums[i] > target) return;

        subset.push_back(nums[i]);
        dfs(res, subset, nums, target-nums[i], i);
        subset.pop_back();
        dfs(res, subset, nums, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(res, subset, nums, target, 0);
        return res;
    }
};