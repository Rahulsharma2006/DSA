class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i =0;i<times.size();i++){
            int sr = times[i][0];
             int dest = times[i][1];
              int w = times[i][2];
              adj[sr].push_back({dest,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
              int d = p.first;
              int node = p.second;
              if(d>dist[node])continue;

              for(int i =0;i<adj[node].size();i++){
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;
                if(d+wt<dist[neigh]){
                    dist[neigh] = d+wt;
                    pq.push({d+wt,neigh});
                }
              }
        }
       int res = dist.empty() ? -1 : *max_element(dist.begin()+1, dist.end());
       if(res==INT_MAX){
        return -1;
       }
        return res;
    }
};