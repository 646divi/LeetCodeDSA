//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findWays(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
        if(n==0){
            if(sum==0 and arr[0]==0)return 2;
            if(arr[0]==sum || sum==0)return 1;
            return 0;
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        int take=0;
        if(arr[n] <= sum)take=findWays(arr,sum-arr[n],n-1,dp);
        int not_take=findWays(arr,sum,n-1,dp);
        return dp[n][sum] = take+not_take;
    }
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int mod=(int)1e9+7;
        int tot_sum=0;
        int n=arr.size();
        for(auto x:arr)tot_sum+=x;
        if((tot_sum-target) < 0 || (tot_sum-target)%2==1)return 0;
        int sum=(tot_sum-target) / 2;
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return findWays(A,sum,n-1,dp);
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        if(arr[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 and arr[0]<=sum)dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int take=0;
                if(arr[i]<=j)take=dp[i-1][j-arr[i]];
                int not_take=dp[i-1][j];
                dp[i][j]=(take+not_take)%mod;
            }
        }
        return dp[n-1][sum];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends