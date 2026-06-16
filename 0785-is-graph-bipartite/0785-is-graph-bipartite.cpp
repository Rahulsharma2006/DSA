class Solution {
public:
   bool res = true;
   void dfs(vector<vector<int>>& graph, int node , vector<int>&color ,int c){
     color[node]=c;
     for(int i =0;i<graph[node].size();i++){
        int neigh = graph[node][i];
    if(color[neigh]==c && color[neigh]!=-1){
            res = false;
    }
    if(color[neigh]==-1){
        dfs(graph,neigh,color,1-c);
    }
     }
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                dfs(graph,i,color,0);
            }
        }
        return res;
    }
};