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
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int tot_sum=0;
        int n=A.size();
        for(auto x:A)tot_sum+=x;
        if((tot_sum-target) < 0 || (tot_sum-target)%2==1)return 0;
        int sum=(tot_sum-target) / 2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return findWays(A,sum,n-1,dp);
        
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