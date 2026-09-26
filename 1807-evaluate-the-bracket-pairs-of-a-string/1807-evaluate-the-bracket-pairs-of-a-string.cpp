class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string ,string>freq;
        for(int i =0;i<knowledge.size();i++){
            string k0 = knowledge[i][0];
             string k1 = knowledge[i][1];
             freq[k0]=k1;
        }
         int i =0;
       while(i<s.size()){
             if(s[i]=='('){
                string temp;
                i++;
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                 if(freq.find(temp)!=freq.end()){
                   ans += freq[temp];
                 }else{
                    ans.push_back('?');
                 }
                 i++;
             }else{
                 ans.push_back(s[i]);
                 i++;
             }
        }
        return ans;
    }
};