class Solution {
public:
       int maxMoney(vector<int>& a, int n , int i ,int free, vector<vector<int>>&Dp){

         if(i>n) return 0;
        
        if(Dp[i][free]!=-1) return Dp[i][free];

        if(free==0)return Dp[i][free]=  maxMoney(a,n,i+1,1,Dp);

        int c1 = a[i] + maxMoney(a,n,i+1,0,Dp);
        int c2 = maxMoney(a,n,i+1,1,Dp);

        return Dp[i][free]= max(c1,c2);
      }
    int rob(vector<int>& nums) {
        int n = nums.size();
           if(n==1) return nums[0];
           
        vector<vector<int>> dp1(n, vector<int>(2, -1));
        vector<vector<int>> dp2(n, vector<int>(2, -1));
         int c1 = maxMoney(nums,n-2,0,1,dp1);
         int c2 = maxMoney(nums,n-1,1,1,dp2);
            return max(c1, c2);
            }
};