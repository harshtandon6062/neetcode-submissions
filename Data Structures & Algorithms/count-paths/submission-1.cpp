class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for(int i = 2; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[n];
    }
};
// 1,1 = 1
// 1,2 = 1
// 2,1 = 1
// 2,2 = 1
// 2,3 = 3
// 3,2 = 3
// 3,3 