class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
          //Approach 1

        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        // for(int i =1;i<nums.size();i++){
        //     if(abs(nums[i]-nums[i-1])>1){
        //         for(int k = nums[i-1]+1;k<nums[i];k++){
        //             ans.push_back(k);
        //         }
        //     }
        // }
        // return ans;
       
         //Approach 2
        //  unordered_map<int,int>mp;
        //  vector<int>ans;
        //  int high =  *max_element(nums.begin(),nums.end());
        //  int low =  *min_element(nums.begin(),nums.end());
        //    for(int i =low;i<=high;i++){
        //     mp[i]++;
        //    }
        //    for (int x : nums)
        //   mp.erase(x);

 
        //  for (auto &it : mp)
        //  ans.push_back(it.first);

        // sort(ans.begin(), ans.end());

        //   return ans;
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        int high =  *max_element(nums.begin(),nums.end());
        int low =  *min_element(nums.begin(),nums.end());
        for(int i =low;i<high;i++){
            if (!st.count(i))
        ans.push_back(i);
}
        return ans;
        
    }
};