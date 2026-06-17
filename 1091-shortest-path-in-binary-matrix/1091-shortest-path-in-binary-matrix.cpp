class Solution {
public:
     bool valid(int row , int col , int n , int m ){
      if(row<0 || col <0 || row >= n || col >= m)return false;
      return true;
     } 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
         if(grid[0][0]==1 || grid[n-1][m-1]==1){
        return -1;
    }
     int dist =0;
     vector<vector<bool>>vis(n);
     for(int i =0;i<n;i++){
        vector<bool>t(m,0);
        vis[i] = t;
     }
     int ans =0;
       queue<tuple<int,int,int>>q;
       q.push({0,0,1});
       vis[0][0] = true;
       while(!q.empty()){
        tuple<int,int,int>p= q.front();
        q.pop();
        
int i = get<0>(p);
int j = get<1>(p);
 dist = get<2>(p);
         if(i == n-1 && j == m-1) return dist;

        int x[8] = {1,1,1,0,-1,-1,-1,0}; 
        int y [8]={-1,0,1,1,1,0,-1,-1};
        for(int k =0;k<8;k++){
         int row = i + x[k];
         int col = j + y[k];
         if(valid(row,col, n , m)&& vis[row][col]==0 && grid[row][col]==0){
            q.push({row,col,dist+1});
            vis[row][col]= true;
         }
        }
       }
       return -1;
    }
};