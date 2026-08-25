class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
    for(int i =0;i<nums.size();i++){
        s.insert(nums[i]);
    }
       int ans =k;
       while(true){
        if(s.find(ans)==s.end()){
            return ans;
        }else{
            ans+=k;
        }
       }
       return -1;
    }
};