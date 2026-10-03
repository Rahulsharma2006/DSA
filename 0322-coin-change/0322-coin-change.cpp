class Solution {
public:
      int helper(vector<int>& coins, int amount,vector<int>& dp){
        if(amount ==0) return 0;
        if(dp[amount]!=-1)return dp[amount];
        int MINI= INT_MAX;
        for(int i =0;i<coins.size();i++){
            if(coins[i]<=amount){
                int val = helper(coins,amount-coins[i],dp);

                if(val!=INT_MAX){
                    MINI = min(MINI,1+val);
                }
            }
        }
        return  dp[amount]=MINI;
      }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = helper(coins,amount,dp);
        if(ans==INT_MAX)return -1;

        return ans;
    }
};