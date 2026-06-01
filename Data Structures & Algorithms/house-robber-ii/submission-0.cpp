class Solution {
public:
    int rob_st(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2);
        for(int i = n-1; i >=0; i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        if (nums.size() < 4) return *max_element(nums.begin(), nums.end());
        // for (auto it: vector<int>(nums.begin()+2, nums.end()-1)){
        //     cout << it << ' ';
        // }
        // return 0;
        vector<int>first (nums.begin()+2, nums.end()-1);
        vector<int>second(nums.begin()+1, nums.end());
        return max((nums[0] + rob_st(first)), rob_st(second));
    }
};
