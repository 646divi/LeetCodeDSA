class Solution {
public:
     int solve(int i,int buy,vector<int>& prices,int n,vector<vector<int>>&dp,int k){
        // if(cap==0)return 0;
        if(i==n || buy==k)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy%2==0){
            profit=max(-prices[i]+solve(i+1,buy+1,prices,n,dp,k),0+solve(i+1,buy,prices,n,dp,k));
        }else{
            profit=max(prices[i]+solve(i+1,buy+1,prices,n,dp,k),0+solve(i+1,buy,prices,n,dp,k));
        }
        return dp[i][buy]=profit;
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(k,-1));
        // return solve(0,0,prices,n,dp,k);
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=2*k-1;buy>=0;buy--){
                int profit=0;
                if(buy%2==0){
                    profit=max(-prices[i]+dp[i+1][buy+1],0+dp[i+1][buy]);
                }else{
                   profit=max(prices[i]+dp[i+1][buy+1],0+dp[i+1][buy]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};