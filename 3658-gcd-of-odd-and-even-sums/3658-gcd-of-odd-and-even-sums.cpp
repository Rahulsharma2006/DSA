class Solution {
public:
    int oddsum(int n ){
        int res=0;
        int num=1;
        while(n--){
                res+=num;
                num+=2;
        }
        return res;
    }
    int evensum(int n ){
        int res=0;
        int num=2;
        while(n--){
            res+=num;
            num+=2;
            }
        return res;
    }
    int gcdOfOddEvenSums(int n) {
        int odd =oddsum(n);
        int even =evensum(n);
        return gcd(odd,even);
    }
};