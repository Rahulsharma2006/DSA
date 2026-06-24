class Solution {
public:
  class Node{
    public:
    int value;
    int row;
    int col;
    Node(int v, int r , int c ){
        value=v;
        row=r;
        col=c;
    }
  }; 
  struct cmp{
    bool operator()(const Node& a , const Node& b){
        return a.value>b.value;
    }
  };
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();
        int cnt =0;
        priority_queue<Node,vector<Node>,cmp>pq;

        for(int i =0;i<n;i++){
         pq.push({matrix[i][0],i,0});
        }
        while(!pq.empty()){
            Node n = pq.top();
            pq.pop();
            cnt++;
            int v = n.value;
            int r = n.row;
            int c = n.col;
            if(cnt==k)return v;

            if(c<m-1){
                pq.push({matrix[r][c+1],r,c+1});
            }
        }
        return -1;
    }
};