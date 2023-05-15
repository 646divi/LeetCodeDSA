class Solution {
public:
    int solve(vector<int>& coins,int s,int i,vector<vector<int>>&dp){
        if(i==0){
            if((s%coins[0])==0)return (s/coins[0]);
            else return 1e9;
        }
        if(dp[i][s]!=-1)return dp[i][s];
        int take=1e9;
        int not_take=0+solve(coins,s,i-1,dp);
        if(coins[i]<=s)take=1+solve(coins,s-coins[i],i,dp);
        return dp[i][s]= min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // if(n==1){
        //     if(amount&coins[0]==0)return amount/coins[0];
        //     else return -1;
        // }
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};