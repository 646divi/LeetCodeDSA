class Solution {
public:
    //Memoization code
    int solve(vector<int>& p,int i,int buy,int n,int fee,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max((-p[i]+solve(p,i+1,0,n,fee,dp)),(0+solve(p,i+1,1,n,fee,dp)));
        }else{
            profit=max((p[i]+solve(p,i+1,1,n,fee,dp))-fee,(0+solve(p,i+1,0,n,fee,dp)));
        }
        return dp[i][buy]=profit;
        
    }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        //--------------------------------------------//
        //---------Memoization part-------------------//
        //--------------------------------------------//
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(prices,0,1,n,fee,dp);
        //--------------------------------------------//
        //---------Memoization part-------------------//
        //--------------------------------------------//
        
        //--------------------------------------------//
        //---------Tabulation part-------------------//
        //--------------------------------------------//
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // for(int i=n-1;i>=0;i--){
        //     int profit=0;
        //     dp[i][1]=max((-p[i]+dp[i+1][0]),(dp[i+1][1]));
        //     dp[i][0]=max((p[i]+dp[i+1][1])-fee,(dp[i+1][0]));
        // }
        // return dp[0][1];
        //--------------------------------------------//
        //---------Tabulation part-------------------//
        //--------------------------------------------//
        
        vector<int>after(2,0);
        vector<int>curr(2,0);
        for(int i=n-1;i>=0;i--){
            int profit=0;
            curr[1]=max((-p[i]+after[0]),(after[1]));
            curr[0]=max((p[i]+after[1])-fee,(after[0]));
            after=curr;
        }
        return after[1];
        
        
    }
};