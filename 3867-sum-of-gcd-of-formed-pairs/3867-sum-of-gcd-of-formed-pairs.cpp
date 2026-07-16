class Solution {
public:
    long long gcdSum(vector<int>& nums) {
           int n = nums.size();
           vector<int>prefix(n);
            prefix[0]=nums[0];
            int maxi = nums[0];
            for(int i =1;i<n;i++){
                maxi=max(maxi,nums[i]);
                prefix[i]=gcd(maxi,nums[i]);
            }
   sort(prefix.begin(),prefix.end());

      int j =0;
      int k = n-1;
      long long ans=0;
      long long res=0;
      while(j<k){
       ans+=gcd(prefix[j],prefix[k]);
       k--;
       j++;
      }
     
    return ans;
    }
};