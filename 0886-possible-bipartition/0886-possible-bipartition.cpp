class Solution {
public:
      bool dfs(vector<vector<int>>& adj,int node , int c , vector<int>& color){
        color[node] = c;
          for(int neigh : adj[node]) {
             if(color[neigh]==c) return false;
                  if(color[neigh]==-1){
                    if(!dfs(adj,neigh,1-c,color)) return false;
                       
                  }
            }
            return true;
        }
      
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       
        vector<vector<int>>adj(n);
        vector<int>color(n,-1);

        for(int i =0;i<dislikes.size();i++){
                int sr = dislikes[i][0] - 1;
                int dest = dislikes[i][1] - 1;
                adj[sr].push_back(dest);
                adj[dest].push_back(sr);
        }
        for( int i=0;i<adj.size();i++){
         if(color[i]==-1){
            if(!dfs(adj,i,1,color)) return false;
         }
        }
        return true;
    }
};