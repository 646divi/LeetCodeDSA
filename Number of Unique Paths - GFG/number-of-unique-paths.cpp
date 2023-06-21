//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int f(int r,int c,int n1,int n2,vector<vector<int>>&dp){
        if(r<0 || c<0 || r>=n1 || c>=n2)return 0;
        if(r==0 and c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int up=f(r-1,c,n1,n2,dp);
        int left=f(r,c-1,n1,n2,dp);
        return dp[r][c]=up+left;
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return f(a-1,b-1,a,b,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends