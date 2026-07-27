class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) 
    {
        int left = 0;
        int right = a.size()-1;
        while(left<=right)
        {
            if (a[left]+a[right] == t)
            return {left+1 , right+1};
            else if (a[left]+a[right] < t) left++;
            else right--;
        }
        return {left+1 , right+1};

        
    }
};
