class Solution {
public:
    long long solve(int i,vector<vector<int>>& q,int n,vector<long long>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long take=0;
        long long not_take=solve(i+1,q,n,dp);
        take=q[i][0]+solve((i+q[i][1]+1),q,n,dp);
        
        return dp[i]= max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return solve(0,questions,n,dp);
    }
};