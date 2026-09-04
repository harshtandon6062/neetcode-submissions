class Solution {
public:
    int climbStairs(int n) {
        int first_prv = 1, second_prv = 1;
        for(int i = 2; i <= n; i++){
            swap(first_prv, second_prv);
            first_prv += second_prv;
            cout << first_prv << ' ' << second_prv;
        }
        return first_prv;
    }
};
// 1,1,2,3
// 5
// 221
// 212
// 122
// 2111
// 1211
// 1121
// 1112
// 11111