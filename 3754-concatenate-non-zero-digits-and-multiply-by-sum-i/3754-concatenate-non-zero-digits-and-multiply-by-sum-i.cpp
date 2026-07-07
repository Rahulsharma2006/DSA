class Solution {
public:
    long long sumAndMultiply(int n) {
        long long val =0;
        long long sum=0;
        while(n!=0){
            int digit = n%10;
            if(digit!=0){
                val=val*10+digit;
            }
            n=n/10;
        }
        long long temp = val;
       
        while(temp!=0){
            int digit = temp%10;
            sum+=digit;
            temp=temp/10;
        }
        long long ans =0;
        while(val!=0){
            ans = ans*10 + val%10;
             val = val/10;
        }
        return ans*sum;
    }
};