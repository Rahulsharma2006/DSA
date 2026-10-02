class Solution {
public:
vector<string> result;
void fun(int open, int close, int n , string temp){
    //Base Case aur Last Case
    if(open ==n && close ==n){
        result.push_back(temp);
        return;
    }
    //Open Parentheses
    if(open<n){
        temp.push_back('(');
         fun(open+1,close,n,temp);
          temp.pop_back();
    }
    //Close Parentheses
    if(close<open){
        temp.push_back(')');
         fun(open,close+1,n,temp);
         temp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
       fun(0,0,n,"");
       return result;
    }
};