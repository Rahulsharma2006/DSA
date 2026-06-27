class Solution {
public:
      int maxMoney(vector<int>& a, int n , int i ,int free, vector<vector<int>>&Dp){

         if(i==n) return 0;

        if(Dp[i][free]!=-1) return Dp[i][free];

        if(free==0)return Dp[i][free]=  maxMoney(a,n,i+1,1,Dp);

        int c1 = a[i] + maxMoney(a,n,i+1,0,Dp);
        int c2 = maxMoney(a,n,i+1,1,Dp);

        return Dp[i][free]= max(c1,c2);
      }
    int rob(vector<int>& nums) {
        int n = nums.size();
          vector<vector<int>>Dp(n);
          for(int i =0;i<n;i++){
            vector<int>t(2,-1);
            Dp[i]=t;
          }
         return maxMoney(nums,n,0,1,Dp);
    }
};