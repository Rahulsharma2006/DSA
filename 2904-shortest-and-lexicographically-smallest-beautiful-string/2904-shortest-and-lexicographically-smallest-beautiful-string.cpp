class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int low =0;
       string res="";
        int n = s.size();
        int cnt = 0;
        for(int high =0;high<n;high++){
            if(s[high]=='1')cnt++;
           
            //Shrinking window
                     while(cnt>k || s[low]=='0'){
                        if(s[low]=='1')cnt--;
                        low++;
                     }
               if(cnt==k){
                 int len = high-low+1;
            string temp = s.substr(low,len);
        if(res.empty() || res.size()>len ||(temp.size()==res.size() && temp<res) ){
                        res = temp;
                     }
               }
                     
        }
        return res;
    }
};