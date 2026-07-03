class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0) return false;
        int temp=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(temp+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j =0;j<=temp;j++){
              if(nums[i]>j){
                dp[i][j]=dp[i+1][j];
              }else{
               
              dp[i][j] = dp[i+1][j] || dp[i+1][j-nums[i]];
            }
            }
        }
        return dp[0][temp];
    }
};