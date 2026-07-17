class Solution {
public:
      bool valid(int r , int c , int n , int m){
        if(r<0 || r>=n || c<0 || c>=m)return false;

        return true;
      }
     void bfs(vector<vector<char>>& grid,int n, int m , int i , int j, vector<vector<bool>>& vis){
        vis[i][j]=true;
        queue<pair<int, int >>q;
        q.push({i,j});
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;
            for(int k=0;k<4;k++){
                int r = row + x[k];
                int c = col + y[k];
            if(valid(r,c,n,m)&&grid[r][c]=='1'&&vis[r][c]==0){
                   vis[r][c]=true;
                   q.push({r,c});
            }
            }
        }
     }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                 if(grid[i][j]=='1'&&vis[i][j]==0){
                    bfs(grid ,  n , m ,  i ,  j ,vis);
                    res++;
                 }
            }
        }
        return res;
    }
};