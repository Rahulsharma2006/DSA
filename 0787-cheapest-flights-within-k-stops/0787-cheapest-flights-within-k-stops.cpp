class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<int>> res(n,vector<int>(k+2,INT_MAX));
res[src][0]=0;
       vector<vector<pair<int,int>>> adj(n);

     for(auto &it : flights){
      int u = it[0];
      int v = it[1];
     int wt = it[2];

    adj[u].push_back({v,wt});
       }
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{src,0}});
       while(!pq.empty()){
        pair<int,pair<int,int>>p = pq.top();
        pq.pop();
        int dis = p.first;
                int node = p.second.first;
                int target = p.second.second;
            for(int j =0;j<adj[node].size();j++){
                int neigh = adj[node][j].first;
                int w = adj[node][j].second;
                if(target<=k && dis + w < res[neigh][target+1]){
                    res[neigh][target+1]=dis+w;
                     pq.push({dis+w,{neigh,target+1}});
                }
            }
       }
        int ans = INT_MAX;

for(int i=0;i<=k+1;i++){
    ans = min(ans,res[dst][i]);
}

return ans==INT_MAX ? -1 : ans;
    }
};