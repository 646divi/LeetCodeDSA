class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            // mat[nrow][ncol]=dis;
            int help[]={0,1,0,-1,0};
            for(int k=0;k<4;k++){
                int nrow=row+help[k];
                int ncol=col+help[k+1];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                    dist[nrow][ncol]=dis+1;
                   
                }
            }
        }
        return dist;
    }
};