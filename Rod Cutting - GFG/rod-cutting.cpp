//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int maxCost(int price[], int n,vector<vector<int>>&dp,int i){
        if(i==0)return price[0]*n;
        if(dp[i][n]!=-1)return dp[i][n];
        int not_take=0+maxCost(price,n,dp,i-1);
        int take=INT_MIN;
        int rl=i+1;
        if(rl<=n)take=price[i]+maxCost(price,n-rl,dp,i);
        
        return dp[i][n]=max(take,not_take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int l=0;l<=n;l++){
                int not_take=dp[i-1][l]+0;
                int take=INT_MIN;
                if((i+1)<=l){
                    take=price[i]+dp[i][l-(i+1)];
                }
                dp[i][l]=max(take,not_take);
            }
        }
        // return maxCost(price,n,vec,n-1);
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends