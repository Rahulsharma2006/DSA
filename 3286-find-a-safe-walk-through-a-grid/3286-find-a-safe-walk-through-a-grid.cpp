class Solution {
public:
    bool valid(int r , int c , int n , int m){
        if(r<0 || c<0 || r>=n || c >= m)return false;
        return true;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       int n = grid.size();
       int m = grid[0].size();
       //Min Heap Banna Lo
       priority_queue<pair<int, pair<int,int>>> pq;
       //Visisted Array
       vector<vector<int>>vis(n,vector<int>(m,-1));
       //4 Direction(right,Left,Up,Down)
       int x[4]={1,-1,0,0};
       int y[4]={0,0,1,-1};
       if(grid[0][0]==1) health--;
       pq.push({health,{0,0}});
       vis[0][0] = health;
         
       while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int val = p.first;
        int row = p.second.first;
        int col = p.second.second;

         if(val <= 0) continue;

          if(row==n-1 && col ==m-1)return true;

          for(int k=0;k<4;k++){
            int r = row + x[k];
            int c = col +y[k];
            
            if(valid(r,c,n,m)){
    int newHealth = val - grid[r][c];

    if(vis[r][c] < newHealth){
        pq.push({newHealth,{r,c}});
        vis[r][c] = newHealth;
    }
}
          }
       }
       return false;
    }
};