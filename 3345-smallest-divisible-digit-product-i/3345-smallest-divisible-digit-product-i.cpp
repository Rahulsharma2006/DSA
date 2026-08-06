class Solution {
public:
    int smallestNumber(int n, int t) {
      
        int temp = n;
            int val =1;
            int curr = temp;
            while(curr!=0){
               val *= (curr % 10);
                curr/=10;
            }
            if(val%t==0)return temp;
            else{
                return smallestNumber(temp+1,t);
            }
        return temp;
    }
};