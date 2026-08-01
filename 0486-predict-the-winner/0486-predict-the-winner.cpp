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
    bool predictTheWinner(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(20,vector<int>(20,-1));
       int p1 =helper(0,n-1,nums,dp);
       int p2=sum-p1;
       return p1>=p2;
    }
};