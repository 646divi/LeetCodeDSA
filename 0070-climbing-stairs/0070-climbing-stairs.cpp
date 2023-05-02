class Solution {
public:
//Top-Down memoizaton+recurssionnapproach wichh has TC:O(N) and SC:O(N)+O(N);
//     int cntSteps(int n,vector<int>&dp){
//         if(n==0)return 1;
//         if(n==1)return 1;
//         if(dp[n]!=-1)return dp[n];
//         dp[n]=cntSteps(n-1,dp)+cntSteps(n-2,dp);
        
//         return dp[n];
//     }
//     int climbStairs(int n){
//         if(n==0)return 0;
//         vector<int>vec(n+1,-1);
//         return cntSteps(n,vec);
        
//     }
    
    int climbStairs(int n){
        if(n==0)return 1;
        int prev=1,prev2=1;
        for(int i=2;i<=n;i++){
            int curr_i=prev+prev2;
            prev2=prev;
            prev=curr_i;
        }
        return prev;
    }
    
    
    
    
    
    
    
    
    
    
    
//this will give TLE as we can see there are overlappin sub probelms we'll use DP
//     int cntSteps(int n,int cnt){
//         if(n==0){
//             cnt++;
//             return cnt;
//         }
//         int left=0;
//         if(n>=2)left=cntSteps(n-2,cnt);
//         int right=cntSteps(n-1,cnt);
        
//         return left+right;
//     }
    
//     int climbStairs(int n) {
//         int cnt=0;
//         if(n==0)return 0;
//         return cntSteps(n,cnt);
//         // return cnt;
//     }
};