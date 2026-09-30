class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans(seq.size());
        int dep =0;
        for(int i =0;i<seq.size();i++){
            if(seq[i]=='('){
                 dep++;
                ans[i]=(dep%2==0)?0:1;
               
            }else{
                ans[i]=(dep%2==0)?0:1;
                dep--;
            }
        }
        return ans;
    }
};