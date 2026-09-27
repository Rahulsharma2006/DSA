class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string , int>mp;
        vector<string>ans;
        if(s.size()<10) return {};
        for(int i =0;i<=s.size()-10;i++){
            auto cs = s.substr(i,10);
            mp[cs]++;
        }
        for(auto &[substr,freq]: mp){
                  if(freq>1){
                    ans.push_back(substr);
                  }
        }
        return ans;
    }
};