class Solution {
public:
    int PathSum(int i, int j , int n , int m ,vector<vector<int>>& grid,vector<vector<int>>&dp ){
        if(i==n-1 && j ==m-1)return dp[i][j]=grid[i][j];
        if(i<0 || i>=n || j<0 || j>=m){
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int c1 = PathSum(i+1,j,n,m,grid,dp);
        int c2 = PathSum(i,j+1,n,m,grid,dp);
        return dp[i][j]=grid[i][j]+min(c1,c2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  PathSum(0,0,n,m,grid,dp);
    }
};