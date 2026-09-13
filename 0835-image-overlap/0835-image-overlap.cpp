class Solution {
public:
     int overlap_count(vector<vector<int>>& A , vector<vector<int>>& B , int row , int col , int n){
        int cnt =0;
        for(int i =0;i<n; i++){
            for(int j =0;j<n;j++){
                int  b_r = i+row;
                int b_c = j + col;
                if(b_r<0 || b_r>=n || b_c<0 || b_c>=n) {
                    continue;
                }
               if(A[i][j] == 1 && B[b_r][b_c] == 1)
                     cnt++;
               
            }
        }
        return cnt;
     }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int row=-n+1;row<n;row++){
            for(int col = -n+1;col<n;col++){
                int count = overlap_count(img1, img2 , row , col,n);
            ans = max(ans , count);
            }
        }
        return ans;
    }
};