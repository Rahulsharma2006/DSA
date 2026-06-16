class Solution {
public:
bool valid (int n , int m , int row , int col){
    if( n < 0 || n>=row || m<0 || m>=col) return false;

    return true;
}
    void dfs(vector<vector<char>>& board,int i , int j , int n , int m ){
        board[i][j]='#';
        int x[4] ={-1,1,0,0};
        int y[4] ={0,0,-1,1};
        for(int k =0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];

            if(valid(row,col,n,m) && board[row][col]=='O'){
                dfs(board,row,col,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         int n = board.size();
         int m = board[0].size();
         //First Row
        for( int j =0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,n,m);
            }
        }
        //Last Row 
        for(int j =0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,n,m);
            }
        }
        //First Col 
        for(int i =0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m);
            }
        }
        //Last Col
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m);
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};