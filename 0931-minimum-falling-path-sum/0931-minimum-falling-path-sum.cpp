class Solution {
public:
    //Memoization + recurrsive
//     int solve(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp){
//         if(j<0 || j>=m)
//             return -1e9;
//         if(i==0)
//             return matrix[0][j];
    
//         if(dp[i][j]!=-1) return dp[i][j];
    
//         int up = matrix[i][j] + solve(i-1,j,m,matrix,dp);
//         int leftDiagonal = matrix[i][j] + solve(i-1,j-1,m,matrix,dp);
//         int rightDiagonal = matrix[i][j] + solve(i-1,j+1,m,matrix,dp);
    
//         return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=0,dr=INT_MAX,dl=INT_MAX;
                up=matrix[i][j]+dp[i-1][j];
                if(j-1>=0)dl=matrix[i][j]+dp[i-1][j-1];
                if(j+1<m)dr=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min({up,dr,dl});
            }
        }
        int maxi = INT_MAX;
    
        for(int j=0; j<m;j++){
             maxi=min(maxi,dp[n-1][j]);
        }
        return maxi;
        
        
        
        
//         vector<vector<int>> dp(n,vector<int>(m,-1));
    
//         int maxi = INT_MIN;
    
//         for(int j=0; j<m;j++){
//              int ans = solve(n-1,j,m,matrix,dp);
//              maxi = max(maxi,ans);
//         }
    
//         return maxi;
    }
};