class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i =1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])>1){
                for(int k = nums[i-1]+1;k<nums[i];k++){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};