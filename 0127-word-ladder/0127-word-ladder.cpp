class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
       int n=wordList.size();
       int i;
       unordered_map<string,int>f;
       for(i=0;i<n;i++){
        f[wordList[i]]=1;
       }
       if(f.find(begin)==f.end()){
        f[begin]=1;
       }
       if(f.find(end)==f.end()){
        return 0;
       }
       queue<pair<string,int>>q;
       q.push({begin,0});
       f.erase(begin);
       while(!q.empty()){
        pair<string,int>p = q.front();
        q.pop();
        string s = p.first;
        int val = p.second;
        if(s==end)return val+1;
        for(int i =0;i<s.size();i++){
            char c = s[i];
        for(int j =97;j<=122;j++){
            if(c-'0'==j) continue;
            s[i]=j;
            if(f.find(s)!=f.end()){
                q.push({s,val+1});
                f.erase(s);
            }
        }
          s[i]=c;
        }
       }
       return 0;
    }

};