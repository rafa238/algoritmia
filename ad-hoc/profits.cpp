//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/s
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=0, max=10000;
        vector<int> profits(prices.size());
        int mayor = -11;
        for(int i=prices.size()-1; i>=0; i--){
            if(mayor<prices[i]){
                mayor = prices[i];   
            }
            profits[i] = mayor - prices[i];
        }
        mayor = -11;
        for(int i=0; i<profits.size(); i++){
            if(mayor<profits[i]) mayor = profits[i]; 
        }
        return mayor;
    }
};