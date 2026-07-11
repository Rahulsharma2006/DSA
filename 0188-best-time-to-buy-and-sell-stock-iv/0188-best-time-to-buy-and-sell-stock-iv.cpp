class Solution {
public:
      int Stocks(int i , int k , int n , vector<int>& prices,vector<vector<int>>&dp){
        if(k==0 || i==n){
            return 0;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        if(k%2==0){
            int c1 = Stocks(i+1,k-1,n,prices,dp)-prices[i];
            int c2 = Stocks(i+1,k,n,prices,dp);
            return dp[i][k]=max(c1,c2);
        }else{
            int c1 = Stocks(i+1,k-1,n,prices,dp)+prices[i];
            int c2 = Stocks(i+1,k,n,prices,dp);
            return dp[i][k]=max(c1,c2);
        }
      }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(k*2+1,-1));
        return Stocks(0,k*2,n,prices,dp);
    }
};