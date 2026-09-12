class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = prices[0], maxP = 0;
        for(int price : prices)
        {
            if(price <= sell) sell = price;
            else
            {
                maxP = max(maxP, price - sell);
            }
        }
        return maxP;
        
    }
};
