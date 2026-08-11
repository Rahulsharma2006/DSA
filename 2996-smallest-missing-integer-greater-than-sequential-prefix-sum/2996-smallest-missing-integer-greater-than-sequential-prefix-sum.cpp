class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find sum of longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Store all elements
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Find smallest missing integer >= sum
        while (freq.find(sum) != freq.end()) {
            sum++;
        }

        return sum;
    }
};