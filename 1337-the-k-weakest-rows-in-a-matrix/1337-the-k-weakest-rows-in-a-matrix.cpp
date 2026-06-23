class Solution {
public:
     int add(vector<int>mat){
        int res =0;
        for(int i =0;i<mat.size();i++){
            if(mat[i]==1){
                res++;
            }
        }
        return res;
     }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i =0;i<mat.size();i++){
            int val = add(mat[i]);
            if(pq.size()<k){
                pq.push({val,i});
            }
            else if (pq.top().first > val){
                pq.pop();
                pq.push({val,i});
            }
        }
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(idx);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};