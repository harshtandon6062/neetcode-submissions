class Solution {
public:
    int rob(vector<int>& nums) {
        int last = nums[0], second_last = 0;
        for(int i = 1; i < nums.size(); i++){
            int cur = max(last, second_last + nums[i]);
            second_last = last;
            last = cur;
        }
        return last;
    }
};
