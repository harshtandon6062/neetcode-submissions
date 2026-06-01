class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_product = nums[0], max_product = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(min_product, max_product);
            max_product = max(nums[i], nums[i] * max_product);
            min_product = min(nums[i], nums[i] * min_product);
            res = max(res, max_product);
        }
        return res;
    }
};
