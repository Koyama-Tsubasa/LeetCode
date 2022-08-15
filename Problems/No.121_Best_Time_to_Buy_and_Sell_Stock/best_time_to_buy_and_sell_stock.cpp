class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // parameters
        int max_profit = 0;
        int price_buy = prices[0];
        
        // start compute
        for (int i=0; i<prices.size(); i++) {
            
            price_buy = min(price_buy, prices[i]);
            max_profit = max(max_profit, prices[i]-price_buy);
            
        }
        
        return max_profit;
        
    }
};
