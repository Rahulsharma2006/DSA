class Solution {
public:
    int leastInterval(vector<char>& a, int gap) {
        int n = a.size();
        unordered_map<char,int>freq;
        unordered_map<char,int>free;
        for(int i =0;i<n;i++){
            freq[a[i]]++;
            free[a[i]]=1;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i : freq){
            pq.push({i.second,i.first});
        }
        int seat =1;
        while(!pq.empty()){
        vector<pair<int,char>>pulled;
        while(!pq.empty()){
            pair<int,char>p = pq.top();
            pq.pop();
            int fr = p.first;
            int child = p.second;
            if(free[child]<=seat){
                if(p.first>1){
                    pq.push({p.first-1,p.second});
                    free[p.second] = seat+gap+ 1;
                   
                }
                 break;
            }else{
                pulled.push_back(p);
            }
        }
        for(int i =0;i<pulled.size();i++){
            pq.push(pulled[i]);
        }
        seat++;
        }
        return seat-1;
    }
};