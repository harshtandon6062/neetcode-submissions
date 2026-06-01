class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& candidates, int target, int i){
        if(target == 0) {
            res.push_back(subset);
            return;
        }
        if(i >= candidates.size() || candidates[i] > target) return;
        subset.push_back(candidates[i]);
        dfs(res, subset, candidates, target-candidates[i], i+1);
        subset.pop_back();
        while(i+1 < candidates.size() && candidates[i+1] == candidates[i])i++;
        dfs(res, subset, candidates, target, i+1);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(res, subset, candidates, target, 0);
        return res;
    }
};
