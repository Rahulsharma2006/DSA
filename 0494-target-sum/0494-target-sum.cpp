class Solution {
public:
      int TargetSum (vector<int>& nums,int n, int target, int i,vector<vector<int>>&dp , int sum ){
        if(abs(target)>sum)return 0;
    
   if(i == n){
    if(target == 0) return dp[i][target + sum]=1;
  return dp[i][target + sum]=0;
    
}
     if(dp[i][target + sum]!=-1)return dp[i][target + sum];

          int c1 =  TargetSum(nums,n,target-nums[i],i+1,dp,sum);
          int c2 =  TargetSum(nums,n,target+nums[i],i+1,dp,sum);

          return dp[i][target + sum]=c1+c2;
      } 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum=sum+nums[i];
        }
       vector<vector<int>> dp(n+1, vector<int>(2*sum+1, -1));
        return  TargetSum(nums,n,target,0,dp,sum);
    }
};