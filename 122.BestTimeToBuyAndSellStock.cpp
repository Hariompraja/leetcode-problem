// 122.BestTimeToBuyAndSellStock
// Dificulty level Easy
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> BestBuy(prices.size());
        BestBuy[0] = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            BestBuy[i] = min(prices[i], BestBuy[i - 1]);
        }

        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            int currentprofit = prices[i] - BestBuy[i];
            maxprofit = max(maxprofit, currentprofit);
        }

        return maxprofit;
    }
};