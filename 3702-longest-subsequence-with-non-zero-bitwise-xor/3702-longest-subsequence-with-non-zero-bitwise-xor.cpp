class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans =0;
        bool allzero=true;;
        for(int i=0;i<nums.size();i++ ){
            ans^=nums[i];
            if(nums[i]!=0){
                allzero=false;
            }
        }
        if(allzero==true)return 0;
        if(ans ==0)return nums.size()-1;
        return nums.size();
    }
};