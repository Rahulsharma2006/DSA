class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n,INT_MAX);
          res[src]=0;
        for(int i =0;i<=k;i++){
               vector<int> temp=res;
            for( int j =0;j<flights.size();j++){
                int sr = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];
            
            if(res[sr]!=INT_MAX && temp[d]>res[sr]+wt){
                temp[d]=res[sr]+wt;
            }
            
        }
        res = temp;
    }
         int ans = res[dst];
         if(ans==INT_MAX) return -1;
            return ans;
    }
};