class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<bool>infect(n,false);
        vector<int>indeg(n,0);
        for(int i =0;i<invocations.size();i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        q.push(k);
        infect[k]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
        
            for(int &i : adj[node]){
                 indeg[i]--;
                if(!infect[i]){
                q.push(i);
               
                infect[i]=true;
                }
            }
        }
        vector<int>ans;
        bool cannotRemove = false;
        for(int i=0;i<n;i++){
         if(infect[i]==true && indeg[i]>0){
            cannotRemove = true;
            break;
         }
         if(infect[i]==false){
            ans.push_back(i);
         }
        }
        if(cannotRemove){
            vector<int>res;
            for(int i =0;i<n;i++){
                res.push_back(i);
            }
            return res;
        }
        return ans;
    }
};