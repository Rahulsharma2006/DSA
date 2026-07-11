class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=4;
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
       for(int i = n-1;i>=0;i--){
        for(int j = 1;j<=k;j++){
            if(j%2==0){
                dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
            }else{
                dp[i][j]=max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
            }
        }
       }
       return dp[0][k];
    }
};