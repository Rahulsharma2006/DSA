class Solution {
public:
    int helper(int l,int r , vector<int>& nums){
        if(l>r)return 0;
        if(l==r)return nums[l];
             int takeleft = nums[l]+min(helper(l+2,r,nums),helper(l+1,r-1,nums));
             int takeright=nums[r]+min(helper(l,r-2,nums),helper(l+1,r-1,nums));
             return max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
       int p1 =helper(0,n-1,nums);
       int p2=sum-p1;
       return p1>=p2;
    }
};