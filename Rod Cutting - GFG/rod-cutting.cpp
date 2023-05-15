//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price [],int i,int len){
      if(i==0){
          return len*price[0];
      }
      int not_take=solve(price,i-1,len);
      int take=INT_MIN;
      int rl=i+1;
      if(rl<=len)take=price[i]+solve(price,i,len-rl);
      return max(take,not_take);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // return solve(price,n-1,n);
        for(int i=0;i<=n;i++){
            dp[0][i]=price[0]*i;
        }
        // for(int i=1;i<n;i++)dp[0][i]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int rl=i+1;
                int not_take=0+dp[i-1][j];
                int take=INT_MIN;
                if(rl<=j)take=price[i]+dp[i][j-rl];
                dp[i][j]=max(take,not_take);
            }
        }
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