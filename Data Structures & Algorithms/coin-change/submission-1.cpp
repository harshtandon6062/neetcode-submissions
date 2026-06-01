// class Solution {
// public:
//     int dp[10001][12];
//     int solve(vector<int>& coins, int amount, int i){
//         if (i >= coins.size() || amount < 0) return -1;
//         if (amount == 0) return 0;
//         if (dp[amount][i] != -1) return dp[amount][i]; 
//         int skip = solve(coins, amount, i+1);
//         int take = solve(coins, amount-coins[i], i);
//         int res;
//         if (skip == -1 && take == -1) return -1;
//         if (skip == -1) return dp[amount][i] = take + 1;
//         if (take == -1) return dp[amount][i] = skip;
//         //return min(1+take, skip);
//         return dp[amount][i] = min(take+1, skip);

//     }
//     int coinChange(vector<int>& coins, int amount) {
//         memset(dp, -1, sizeof(dp));
//         int res = solve(coins, amount, 0); 
//         return res; 
//     }
// };
class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1));
        for(int i = 1; i <= amount; i++){
            dp[i][0] = INT_MAX;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= amount; i++){
            for(int j = 1; j <= n; j++){
                int k = i-coins[j-1];
                int take = (k >= 0 && dp[k][j] < INT_MAX)  ? 1+dp[k][j] : INT_MAX;
                int skip = dp[i][j-1];
                dp[i][j] = min(take, skip);
            }
        }
        return (dp[amount][n] != INT_MAX) ? dp[amount][n]: -1;
    }
};
