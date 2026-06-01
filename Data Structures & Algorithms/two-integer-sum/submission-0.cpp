class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if (nums_map.count(difference)){
                res.push_back(nums_map[difference]);
                res.push_back(i);
                break;
            }
            nums_map[nums[i]] = i;
        }
        return res;


    }
};
