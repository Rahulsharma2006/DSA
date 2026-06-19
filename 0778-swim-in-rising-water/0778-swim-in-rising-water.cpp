class Solution {
public:
     bool valid( int row , int col , int n , int m){
        if(row<0 || col < 0 || row>=n || col>= m)return false;
        return true;
     }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n ,vector<int>(m,1e8));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int x[4] ={-1,1,0,0};
        int y[4]={0,0,-1,1};
        res[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
             pair<int,pair<int,int>>p = pq.top();
             pq.pop();
             int d = p.first;
             int row = p.second.first;
             int col = p.second.second;
             if(d>res[row][col]) continue;
             for(int i =0;i<4;i++){
                int r = row+x[i];
                int c = col + y[i];
                if(!valid(r,c,n,m)) continue;
               int newCost=max(d,grid[r][c]);

       if(newCost < res[r][c])
       {
        res[r][c]=newCost;
    pq.push({newCost,{r,c}});
       }
             }
        }
        return res[n-1][m-1];
    }
};