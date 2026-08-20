class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a1;
        vector<int>a2;
        a1.push_back(nums[0]);
       a2.push_back(nums[1]);
       for(int i =2 ; i<nums.size();i++){
        int n = a1.size();
        int m = a2.size();
        if(a1[n-1]>a2[m-1]){
            a1.push_back(nums[i]);
        }else{
            a2.push_back(nums[i]);
        }
       }
      vector<int >ans;
      for(int a : a1){
        ans.push_back(a);
      }
       for(int b : a2){
        ans.push_back(b);
      }
      return ans;
    }
};