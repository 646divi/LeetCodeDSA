class Solution {
public:
    //meoizATION AND recurrsion
//     int solve(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
//         if(r==0 and c==0)return 1;
//         if(grid[r][c]==1)return 0;
//         if(dp[r][c]!=-1)return dp[r][c];
//         int left=0,right=0;
//         if(c>0)left=solve(r,c-1,grid,dp);
//         if(r>0)right=solve(r-1,c,grid,dp);
        
//         return dp[r][c]=left+right;
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int left=0;
                int right=0;
                if(i>0)left=dp[i-1][j];
                if(j>0)right=dp[i][j-1];
                dp[i][j]= left+right;
            }
        }
        return dp[n-1][m-1];
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,obstacleGrid,dp);
    }
};