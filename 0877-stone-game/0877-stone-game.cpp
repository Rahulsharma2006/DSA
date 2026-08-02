class Solution {
public:
    int helper(int l,int r , vector<int>& nums,vector<vector<int>>&dp){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        if(l==r)return nums[l];
             int takeleft = nums[l]+min(helper(l+2,r,nums,dp),helper(l+1,r-1,nums,dp));
             int takeright=nums[r]+min(helper(l,r-2,nums,dp),helper(l+1,r-1,nums,dp));
             return dp[l][r]=max(takeleft,takeright);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum =0;
        for(int p : piles){
              sum+=p;
        }
         vector<vector<int>>dp(n,vector<int>(n,-1));
       int p1 =helper(0,n-1,piles,dp);
       int p2=sum-p1;
       return p1>=p2;

    }
};