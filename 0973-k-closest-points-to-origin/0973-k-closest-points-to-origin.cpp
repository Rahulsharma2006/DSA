class Solution {
public:
    int square(int a , int b){
        if(a==0 && b == 0)return 0;
        return a*a+b*b;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,int>freq;
        for(int i =0;i<points.size();i++){
            int sqt = square(points[i][0],points[i][1]);
            freq[i]=sqt;
        }
        priority_queue<pair<int,int>>pq;
        for(pair<int,int> p : freq){
            int index = p.first;
            int val = p.second;
            if(pq.size()<k){
                pq.push({val,index});
            }
            else if ( pq.top().first > val){
                pq.pop();
                pq.push({val,index});
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            ans.push_back({points[index][0],points[index][1]});
        }
        return ans;
    }
};