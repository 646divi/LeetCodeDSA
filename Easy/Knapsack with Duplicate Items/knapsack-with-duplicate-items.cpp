//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N, int W, int val[], int wt[],vector<vector<int>>&dp){
        if(W==0)return 0;
        if(N==0)return val[0]*(W/wt[0]);
        if(dp[N][W]!=-1)return dp[N][W];
        int take=0;
        int ntake=solve(N-1,W,val,wt,dp);
        if(wt[N]<=W)take=val[N]+ solve(N,W-wt[N],val,wt,dp);
        return dp[N][W] = max(take,ntake);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends