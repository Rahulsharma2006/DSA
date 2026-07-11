class Solution {
public:
     int Profit(vector<int>& prices,int n , int i , int k ,vector<vector<int>>& dp){
        if(i==n || k==0){
            return 0;
        }
           if(dp[i][k]!=-1)return dp[i][k];
          //Even Case ---> Buy Stocks
        if(k%2==0){
           int c1 = Profit(prices,n,i+1,k-1,dp) - prices[i];
           int c2 = Profit(prices,n,i+1,k,dp);
           return dp[i][k]=max(c1,c2);
        }else{
          int c1 = Profit(prices,n,i+1,k-1,dp)+prices[i];
           int c2 = Profit(prices,n,i+1,k,dp);
           return dp[i][k]=max(c1,c2);
        }
     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return Profit(prices,n,0,4,dp);
    }
};