class Solution {
public:
   struct cmp{
    bool operator()(pair<int,string>& a, pair<int,string>& b){

        if(a.first == b.first)
            return a.second < b.second;

        return a.first > b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(int i =0;i<words.size();i++){
            freq[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
         for(pair<const string,int>p : freq){
            string word = p.first;
            int f = p.second;
            if(pq.size()<k)pq.push({f,word});

            else if(pq.top().first<f || (f == pq.top().first && word < pq.top().second)){
                pq.pop();
                pq.push({f,word});
            }
         }
         vector<string>ans;
         while(!pq.empty()){
            pair<int,string>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};