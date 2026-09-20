class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            int idx = i+1;
            int val = 26-(ch-'a');
            int pro = val*idx;
            ans +=pro;
        }
        return ans;
    }
};