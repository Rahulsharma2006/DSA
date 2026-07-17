class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>freq;
        freq[0] =-1;
        int sum =0;
        int ans =0;
        for(int i =0;i<nums.size();i++){
             sum += (nums[i] == 0 ? -1 : 1);
            if(freq.find(sum)!=freq.end()){
                ans = max(ans, i - freq[sum]);
            }else{
               freq[sum] = i;
            }
        }
        return ans;
    }
};