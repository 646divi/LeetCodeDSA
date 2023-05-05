class Solution {
public:
    //Memoization + recurrsion with TC:O(n*m) and SC:O(n-1 * m-1) + recurrsion call stack
    // int solve(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
    //     if(r==0 and c==0){
    //         return grid[0][0];
    //     }
    //     if(dp[r][c]!=-1)return dp[r][c];
    //     int left=INT_MAX,right=INT_MAX;
    //     if(r>0)left=solve(r-1,c,grid,dp)+grid[r][c];
    //     if(c>0)right=solve(r,c-1,grid,dp)+grid[r][c];
    //     return dp[r][c]=min(left,right);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
        
        
        
        
        
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,grid,dp);
        
    }
};