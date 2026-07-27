class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int d1=-1;
        int d2 =-1;
        // nums = [3,4,5,2]

        //Max Heap Banna lete Haine 2 Size ka heap(5,4)
      priority_queue <int, vector<int>, greater<int> > pq;
        for(int i =0;i<2;i++){
            pq.push(nums[i]);
        }
        for(int i =2;i<n;i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
      while(!pq.empty()){
        int val = pq.top();
        pq.pop();
        if(val>=d1){
            d2=d1;
            d1=val;
        }else{
            d2=val;
        }
      }
      return (d1-1)*(d2-1);
    }
};