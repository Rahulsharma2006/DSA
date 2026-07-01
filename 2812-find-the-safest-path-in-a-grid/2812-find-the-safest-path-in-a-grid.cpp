class Solution {
public:
     bool valid(int row , int col , int n){
        if(row<0 || col<0 || row>=n || col>=n) return false;

        return true;
     }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
       queue< pair<int, int>> q;
      
         vector<vector<int>>dist(n,vector<int>(n,-1));
       int x[4]={1,0,-1,0};
       int y[4] ={0,1,0,-1};
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]!=0){
                    dist[i][j]=0;
                    q.push({i,j});
             
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            int val = dist[r][c];
            q.pop();
            for(int k =0;k<4;k++){
                int row = r + x[k];
                int col = c + y[k];
              if(valid(row,col,n)&&dist[row][col]==-1){
                    dist[row][col]=val+1;
                      q.push({row,col});
                  
                   
              }
            }
        }
        if(dist[0][0]==0 || dist[n-1][n-1]==0) return 0;

       priority_queue<pair<int, pair<int,int>>> pq;

vector<vector<int>> best(n, vector<int>(n, -1));

     best[0][0] = dist[0][0];
    pq.push({dist[0][0], {0, 0}});

     while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    int safe = curr.first;
    int r = curr.second.first;
    int c = curr.second.second;

    // Destination reached
    if (r == n - 1 && c == n - 1)
        return safe;

    for (int k = 0; k < 4; k++) {
        int nr = r + x[k];
        int nc = c + y[k];

        if (!valid(nr, nc, n))
            continue;
        int newSafe = min(safe, dist[nr][nc]);

        if (newSafe > best[nr][nc]) {
            best[nr][nc] = newSafe;
            pq.push({newSafe, {nr, nc}});
        }
       }
     }
       return 0;

    }
};