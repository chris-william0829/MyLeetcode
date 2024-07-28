/*

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
2024-7-28


*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1] > 0){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};