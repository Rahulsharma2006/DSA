class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           unordered_map<string, vector<string>>freq;
           for(auto& str: strs){
            string key = str;
            sort(key.begin(),key.end());
            freq[key].push_back(str);
           }
           vector<vector<string>>res;
         for(auto& it : freq){
            res.push_back(it.second);
         }
          return res;
    }
};