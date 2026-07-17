class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int low =0;
          int high =0;
          int n = nums.size();
          int sum=0;
      while(high<n){
       sum+=nums[high];
       while(sum>=target){
        ans=min(ans,high-low+1);
        sum=sum-nums[low];
        low++;
       }
       high++;
        }
    if(ans==INT_MAX)return 0;

    return ans;
    }
};