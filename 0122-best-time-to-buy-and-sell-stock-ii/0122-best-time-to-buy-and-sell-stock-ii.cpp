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
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // // return solve(0,prices, n,1,dp);
        // dp[n][0]=dp[n][1]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         int profit=0;
        //         if(j){
        //             profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
        //         }else{
        //             profit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
        //         }
        //        dp[i][j]= profit;
        //     }
        // }
        // return dp[0][1];
        vector<int>ahead(2,0),curr(2,0);
        // return solve(0,prices, n,1,dp);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+ahead[0],0+ahead[1]);
                }else{
                    profit=max(prices[i]+ahead[1],0+ahead[0]);
                }
               curr[j]= profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};