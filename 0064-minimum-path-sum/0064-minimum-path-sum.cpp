class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(r==0 and c==0){
            return grid[0][0];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int left=INT_MAX,right=INT_MAX;
        if(r>0)left=solve(r-1,c,grid,dp)+grid[r][c];
        if(c>0)right=solve(r,c-1,grid,dp)+grid[r][c];
        return dp[r][c]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
        
    }
};