class Solution {
public:
    const int mod = 1e9 + 7;
   int PairCount(vector<int>& nums,int i , int first , int second,vector<vector<vector<int>>>&dp){
      
    if(i==nums.size()){
        if(first!=0 && second!=0){
            if(first==second) return dp[i][first][second]=1;
        }
        return dp[i][first][second]= 0;
    }
      if(dp[i][first][second]!=-1)return dp[i][first][second];
    int skip = PairCount(nums,i+1,first,second,dp);
    int newFirst = (first == 0) ? nums[i] : gcd(first, nums[i]);
    int newSecond = (second == 0) ? nums[i] : gcd(second, nums[i]);
    int take1 =PairCount(nums,i+1,newFirst,second,dp);
    int take2 = PairCount(nums,i+1,first,newSecond,dp);
    return dp[i][first][second]= ((skip + take1) % mod + take2) % mod;;
   }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(mx+1,vector<int>(mx+1,-1)));
        return PairCount(nums,0,0,0,dp);
    }
};