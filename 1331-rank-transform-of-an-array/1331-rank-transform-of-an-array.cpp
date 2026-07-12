class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;
        int r =1;
        for(auto &x : temp){
            if(rank.find(x)==rank.end()){
                rank[x]=r++;
            }
        }
           vector<int>ans;
        for(auto &x : arr){
         ans.push_back(rank[x]);
        }
        return ans;
    }
};