class Solution {
public:
    string smallestPalindrome(string s) {
       int n = s.size();
      int mid = n/2;
      string s1;
       for(int i =0;i<mid;i++){
        s1.push_back(s[i]);
       }
       sort(s1.begin(),s1.end());
       string ans;
       string rev = s1; 
       reverse(rev.begin(), rev.end()); 
       if(n%2==0){
        ans = s1+rev;
       }else{
        ans = s1+s[mid]+rev;
       }
       return ans;
    }
};