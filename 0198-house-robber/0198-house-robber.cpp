class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
         if(nums.size()==0) return 0;
         if(nums.size()==1) return nums[0];
         int prev_prev=0;
         int prev=nums[n-1];
         
         int ans =0;
    for(int i=n-2;i>=0;i--){
       ans = max(nums[i]+prev_prev,prev);
       prev_prev=prev;
       prev=ans;
    }
    return ans;
    }
};