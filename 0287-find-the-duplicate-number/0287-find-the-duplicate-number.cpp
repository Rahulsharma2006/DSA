class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Step1 :Make This Array like a LL and use Fast and Slow Pointer Approach [1,2,3,2,2]
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Step 2 Now [ 1 , 2 , 3 , 2 , 2] Both Slow And Fast on Index 2 Element 3

      int slow2=0;
      //Step 3 Use Third Pointer and Whic Work as a Slow Pointer (Slow2)
      while(slow2!=slow){
        slow= nums[slow];
        slow2=nums[slow2];
      }
       //Step4 : Now Both Slow and Slow2 Both on Same Elment and Return it
      return slow;
    }
};
