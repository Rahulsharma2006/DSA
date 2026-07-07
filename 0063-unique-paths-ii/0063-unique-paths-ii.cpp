class Solution {
public:
       int Paths(int i , int j , int n , int m ,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(i==n-1 && j == m-1 && obstacleGrid[i][j]==0)return dp[i][j]=1;
        if(i<0 || i>=n || j<0 || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(obstacleGrid[i][j]==1)return dp[i][j]=0;
        
        return dp[i][j]=Paths(i,j+1,n,m,obstacleGrid,dp)+Paths(i+1,j,n,m,obstacleGrid,dp);

       }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return Paths(0,0,n,m,obstacleGrid,dp);
    }
};