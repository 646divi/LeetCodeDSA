class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
        // if(cap==0)return 0;
        if(i==n || buy==4)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy%2==0){
            profit=max(-prices[i]+solve(i+1,buy+1,prices,n,dp),0+solve(i+1,buy,prices,n,dp));
        }else{
            profit=max(prices[i]+solve(i+1,buy+1,prices,n,dp),0+solve(i+1,buy,prices,n,dp));
        }
        return dp[i][buy]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        // return solve(0,0,prices,n,dp);
        vector<int>ahead(5,0);
        vector<int>curr(5,0);
        for(int i=n-1;i>=0;i--){
            for(int j=3;j>=0;j--){
                int profit=0;
                if(j%2==0){
                    profit=max(-prices[i]+ahead[j+1],0+ahead[j]);
                }else{
                    profit=max(prices[i]+ahead[j+1],0+ahead[j]);
                }
                curr[j]=profit;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};