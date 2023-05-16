class Solution {
public:
    int solve(int i,vector<int>& prices,int n,int buy, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(i+1,prices,n,0,dp),0+solve(i+1,prices,n,1,dp));
        }else{
            profit=max(prices[i]+solve(i+1,prices,n,1,dp),0+solve(i+1,prices,n,0,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices, n,1,dp);
    }
};