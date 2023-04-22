//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //Memoization based solution which is top down approach 
    // int FindEnergy(vector<int>&height,int idx,vector<int>&dp){
    //     if(idx==0)return 0;
    //     if(dp[idx]!=-1)return dp[idx];
    //     int left=FindEnergy(height,idx-1,dp) + abs(height[idx]-height[idx-1]);
    //     int right=INT_MAX;
    //     if(idx>1){
    //         right=FindEnergy(height,idx-2,dp) +abs(height[idx]-height[idx-2]);
    //     }
    //     return dp[idx]=min(left,right);
    // }
    
    //Tabulation approach which is also known as bottom up DP
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n<0)return 0;
        vector<int>dp(n+1,0);
        // return FindEnergy(height,n-1,dp);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int oneForward=dp[i-1]+abs(height[i]-height[i-1]);
            int twoForward=INT_MAX;
            if(i>1)twoForward=dp[i-2]+abs(height[i]-height[i-2]);
            dp[i]=min(oneForward,twoForward);
        }
        
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends