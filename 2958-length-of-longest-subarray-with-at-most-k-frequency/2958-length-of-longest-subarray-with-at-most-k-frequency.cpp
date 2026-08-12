class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans =0;
        unordered_map<int,int>freq;
        int low =0;
        int n = nums.size();
       for(int high=0;high<n;high++){
            freq[nums[high]]++;
            while(freq[nums[high]]>k){
                freq[nums[low]]--;
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};