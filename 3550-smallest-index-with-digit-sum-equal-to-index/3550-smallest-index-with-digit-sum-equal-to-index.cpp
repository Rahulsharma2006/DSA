class Solution {
public:
   int helper(int val){
    int ans = 0;
    while(val>0){
        int a = val%10;
        ans+=a;
        val/=10;
    }
    return ans;
   }
    int smallestIndex(vector<int>& nums) {
     
       for(int i =0;i<nums.size();i++){
          int val = helper(nums[i]);
          if(val==i)return i;
       }
       return -1; 
    }
};