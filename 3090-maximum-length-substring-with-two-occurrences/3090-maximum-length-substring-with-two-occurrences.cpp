class Solution {
public:
    int maximumLengthSubstring(string s) {
        int low =0;
        int ans = 0;
        unordered_map<char,int>freq;
        for(int high =0;high<s.size();high++){
            freq[s[high]]++;
            while(freq[s[high]]>2){
                freq[s[low]]--;
                low++;
            }
            
              ans = max(ans,high-low+1);
            
        }
        return ans;
    }
};