class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - lowest_price;
            max_profit = max(profit, max_profit);
            lowest_price = min(lowest_price, prices[i]);
        }
        return max_profit;
    }
};
