class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit =0;
        int min_val = INT_MAX;
        if(prices.size()==0 or prices.size()==1){
            return 0;
        }
        for(int i =0;i<prices.size();i++){
            min_val = min(min_val,prices[i]);
            Profit = max(Profit,prices[i]-min_val);
        }
        return Profit;
    }
};