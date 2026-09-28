class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        st.push(0);
        int ans = INT_MIN;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            int val = st.top();
            st.pop();
            st.push(val+1);
        }
        if(s[i]==')'){
            int val = st.top();
            ans = max(ans , val);
            st.push(val-1);
        }
       }
       if(ans==INT_MIN)return 0;
       return ans;
    }
};