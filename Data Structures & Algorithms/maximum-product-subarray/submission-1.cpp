class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_product = nums[0];
        int max_product = nums[0];
        int res = max_product;
        for(int i = 1; i < n; i++){
            int new_min_product = min({nums[i]*max_product, nums[i]*min_product, nums[i]});
            int new_max_product = max({nums[i]*max_product, nums[i]*min_product, nums[i]});
            min_product = new_min_product;
            max_product = new_max_product;
            res = max(res, max_product);
        }
        return res;
        
    }
};
