class Solution {
public:
     int Findsum(int n){
           int ans =0;
           while(n!=0){
            ans +=n%10;
            n/=10;
           }
           return ans;
     }
          int FindProduct(int n){
           int ans =1;
           while(n!=0){
            ans *=n%10;
            n/=10;
           }
           return ans;
     }
     
    bool checkDivisibility(int n) {
        int sum = Findsum(n);
        int product = FindProduct(n);
        int val = sum+product;
        if(n%val==0){
            return true;
        }
        return false;
    }
};