class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto& edge: prerequisites){
            int sr = edge[0];
            int dest = edge[1];
            adj[dest].push_back(sr);
                     indeg[sr]++;
        }
          queue<int>q;
        for(int i=0;i<adj.size();i++){
            if(indeg[i]==0){
                q.push({i});
            }
        }
        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
          for(auto& neigh : adj[node]){
            indeg[neigh]--;
            if(indeg[neigh]==0){
                q.push(neigh);
            }
          }
        }
        return count == numCourses;
    }
};