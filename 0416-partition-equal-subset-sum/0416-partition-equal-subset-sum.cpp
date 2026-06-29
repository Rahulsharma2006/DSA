class Solution {
public:
     bool Partition(vector<int>& nums, int n , int sum , int i,vector<vector<int>>& dp){
          if(sum==0) return true;
     if(i==n) return false;
     if(dp[i][sum]!=-1)return dp[i][sum];
     bool c1 = false;
     if(nums[i]<=sum){
       c1 = Partition(nums,n, sum - nums[i] , i+1,dp);
     }
      bool c2 = Partition(nums,n,sum,i+1,dp);
       return dp[i][sum] = c1 || c2;
}

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
       
        for(int i =0;i<n;i++){
          sum+=nums[i];
        }
         vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        if(sum%2!=0) return false;

        return Partition(nums,n,sum/2,0,dp);
    }
};