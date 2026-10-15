class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans =0;
        for(int i =0;i<nums.size();i++){
           unordered_set<int>freq;
            for(int j = i;j<nums.size();j++){
                  freq.insert(nums[j]);
                   int count = freq.size();
            ans+=count*count;
            }
           
        }
        return ans;
    }
};