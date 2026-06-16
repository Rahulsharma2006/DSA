class Solution {
public:
 
   bool dfs(vector<vector<int>>& graph, int node , vector<int>&color ,int c){
     color[node]=c;
     for(int i =0;i<graph[node].size();i++){
        int neigh = graph[node][i];
    if(color[neigh]==c) return false;
    if(color[neigh]==-1)
        if(!dfs(graph,neigh,color,1-c)) return false;
    
     }
     return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,0)) return false;
            }
        }
        return true;;
    }
};