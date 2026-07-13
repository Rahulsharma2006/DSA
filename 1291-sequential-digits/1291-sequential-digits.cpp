class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;

        for(int i =1;i<9;i++){
            q.push(i);
        }
       vector<int>ans;
        //Using Bfs 
        while(!q.empty()){
            int ld = q.front();
            q.pop();
            int digit = ld%10;
            if(digit==9)continue;
            ld = ld*10+digit+1;
            if(ld<low){
            q.push(ld);
            }
            if(ld>= low&& ld<=high){
                   ans.push_back(ld);
                   q.push(ld);
            }
        }
        return ans;
    }
};