class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, int taken){
        if (i >= coins.size() || amount < 0) return INT_MAX;
        if (amount == 0) return taken;
        int skip = solve(coins, amount, i+1, taken);
        int take = solve(coins, amount-coins[i], i, taken + 1);
        return min(take, skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        int res = solve(coins, amount, 0, 0); 
        return (res != INT_MAX) ? res: -1; 
    }
};
