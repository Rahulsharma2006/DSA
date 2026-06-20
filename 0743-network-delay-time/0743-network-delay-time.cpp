class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>res(n+1,INT_MAX);
        res[k] =0;

        for(int i =0;i<n-1;i++){
            for(int j =0;j<times.size();j++){
                int sr = times[j][0];
                int d = times[j][1];
                int wt = times[j][2];
                if(res[sr]!=INT_MAX && res[d]>res[sr]+wt){
                    res[d]=res[sr]+wt;
                }
            }
        }
        
        if(*max_element(res.begin()+1,res.end())==INT_MAX)return -1;
        return *max_element(res.begin()+1,res.end());
    }
   
};