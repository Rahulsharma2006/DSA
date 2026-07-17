class Solution {
public:
 bool valid(int i , int j , int n , int m){
        if( i<0 || i>=n || j<0 || j>=m ){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        int time=0;
         queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty()&& fresh>0){
            time++;
            int s = q.size();
            while(s--){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
          
            for(int k=0;k<4;k++){int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
                int r = row+x[k];
                int c = col+y[k];
                if(valid(r,c,n,m)&&grid[r][c]==1){
                    grid[r][c]=2;
                    q.push({r,c});
                    fresh--;
                }
            }
            }
        }
        if(fresh>0)return -1;
        return time;
    }
};