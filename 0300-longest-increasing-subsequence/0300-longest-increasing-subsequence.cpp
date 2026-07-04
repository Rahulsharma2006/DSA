class Solution {
public:
      int SubString(vector<int>& nums,int n , int i , int prev,vector<vector<int>>&dp ){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        if(prev==-1 or nums[i]>nums[prev]){
            int c1 = 1 + SubString(nums,n,i+1,i,dp);
            int c2 = SubString(nums,n,i+1,prev,dp);
            return dp[i][prev+1]=max(c1,c2);
        }
        return dp[i][prev+1]=SubString(nums,n,i+1,prev,dp);
      }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
          vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return SubString(nums,n,0,-1,dp);
    }
};