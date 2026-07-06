class Solution {
public:
    int LongChain(vector<vector<int>>& pairs, int n , int i, int prev,vector<vector<int>>&dp){
        if(i==n)return 0;
          if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1 ||pairs[i][0] >pairs[prev][1] ){
            int c1 = 1+LongChain(pairs,n,i+1,i,dp);
            int c2 = LongChain(pairs,n,i+1,prev,dp);
            return dp[i][prev+1]=max(c1,c2);
        }
        return dp[i][prev+1]=LongChain(pairs,n,i+1,prev,dp);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
            int n = pairs.size();
            vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            sort(pairs.begin(), pairs.end());
          return LongChain(pairs,n,0,-1,dp);
    }
};