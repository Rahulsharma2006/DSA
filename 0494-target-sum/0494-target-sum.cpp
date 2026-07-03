class Solution {
public:
      int TargetSum (vector<int>& nums,int n, int target, int i ){
   if(i == n){
    if(target == 0) return 1;
    return 0;
}

          int c1 =  TargetSum(nums,n,target-nums[i],i+1);
          int c2 =  TargetSum(nums,n,target+nums[i],i+1);

          return c1+c2;
      } 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return TargetSum(nums,n,target,0);
    }
};