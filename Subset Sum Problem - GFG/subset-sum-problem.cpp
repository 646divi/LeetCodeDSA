//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(vector<int>arr,int sum,int n,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(n==0)return sum==arr[0];
        if(dp[n][sum]!=-1)return dp[n][sum];
        int take=0;
        if(arr[n] <=sum){
            take=f(arr,sum-arr[n],n-1,dp);
        }
        int not_take=f(arr,sum,n-1,dp);
        return dp[n][sum]=take||not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(arr,sum,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends