class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        auto helper = [&nums, n] (auto& self, int i){
            if(i == n) return vector<vector<int>>(1,vector<int>(0));
            vector<vector<int>> res = self(self,i+1);
            int res_size = res.size();
            for(int x = 0; x < res_size; x++){
                res.push_back(res[x]);
                res.back().push_back(nums[i]);
            }
            return res;
        };
        return helper(helper, 0);
    }
};
