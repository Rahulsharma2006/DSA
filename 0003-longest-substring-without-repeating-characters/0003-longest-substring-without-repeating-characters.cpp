class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>freq;
        int low =0;
        int ans =0;
        for(int high =0;high<s.size();high++){
            freq[s[high]]++;
            while(freq[s[high]]>1){
                freq[s[low]]--;
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};