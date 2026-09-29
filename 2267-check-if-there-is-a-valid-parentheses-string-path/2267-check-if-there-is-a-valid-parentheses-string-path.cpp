class Solution {
public:
   int n;
   int m;
   int dp[101][101][202];
    bool hasValidPath(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();

        if((m+n-1)%2==1 || grid[0][0]==')' || grid[n-1][m-1]=='(')return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
    bool solve(int i , int j , int open,vector<vector<char>>& grid){
        open+=(grid[i][j]=='(')?1:-1;
         if(open<0)return false;
        if(dp[i][j][open]!=-1)return dp[i][j][open];
       
        if(i==n-1 && j==m-1){
                     return dp[i][j][open]=(open==0);
        }
        //Down Jao
        if(i+1<n){
            if(solve(i+1,j,open,grid)) return dp[i][j][open]=true;
        }
        //Right Jao
           if(j+1<m){
            if(solve(i,j+1,open,grid)) return dp[i][j][open]=true;
        }
        return dp[i][j][open]=false;
    }
};