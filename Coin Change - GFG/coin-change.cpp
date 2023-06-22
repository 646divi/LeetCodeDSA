//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int f(int coins[], int N, int sum){
        if(sum==0)return 1;
        if(N==0){
            if(sum>=coins[N] and sum%coins[N]==0)return 1;
            else return 0;
        }
        long long int take=0;
        if(coins[N]<=sum)take=f(coins,N,sum-coins[N]);
        long long int not_take=f(coins,N-1,sum);
        
        return take+not_take;
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
        for(int i=0;i<N;i++)dp[i][0]=1;
        for(int i=1;i<=sum;i++){
            if(i%coins[0] == 0)dp[0][i]=1;
        }
        for(int i=1;i<N;i++){
            for(int j=1;j<=sum;j++){
                long long int take=0;
                if(j>=coins[i])take=dp[i][j-coins[i]];
                long long int not_take=dp[i-1][j];
                dp[i][j]=take+not_take;
            }
        }
        return dp[N-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends