class Solution {
public:
    vector<vector<int>> solve(vector<vector<vector<vector<int>>>>& dp, vector<int>& nums, int target, int i){
        if (target == 0) return {{}};
        int n = nums.size();
        if(i >= n || target < 0) return {};
        if(!dp[target][i].empty()) return dp[target][i];
        vector<vector<int>> take = solve(dp, nums, target-nums[i], i);
        vector<vector<int>> skip = solve(dp, nums, target, i+1);
        // Push num into every inner vector of take
        for (auto& vec : take) {
            vec.push_back(nums[i]);
        }
        // Merge skip into take
        take.insert(take.end(), skip.begin(), skip.end());
        return dp[target][i] = take; // merged result
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<vector<vector<int>>>> dp(target+1, vector<vector<vector<int>>>(nums.size()));
        return solve(dp, nums, target, 0);
    }
};
