class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int ans = -1;
       if(k==n){
     return *max_element(nums.begin(),nums.end());
       }
        for(int a : nums){
            freq[a]++;
        }
       if(k==1){
          for(int i =0;i<nums.size();i++){
               if(freq[nums[i]]==1){
                ans = max(ans,nums[i]);
               }
          }
       
       }else{
        if(freq[nums[0]]==1 ){
            ans = max(ans,nums[0]);
        }
        if(freq[nums[n-1]]==1){
            ans = max(ans,nums[n-1]);
        }
       }
       return ans;
    }
};