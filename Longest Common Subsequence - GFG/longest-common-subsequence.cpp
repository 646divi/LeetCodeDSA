//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int LCS(string s1,string s2,int n1,int n2,vector<vector<int>>&dp){
        if(n1<0 || n2<0)return 0;
        if(dp[n1][n2]!=-1)return dp[n1][n2];
        if(s1[n1]==s2[n2])return dp[n1][n2] = 1+LCS(s1,s2,n1-1,n2-1,dp);
        return dp[n1][n2] = max(LCS(s1,s2,n1-1,n2,dp),LCS(s1,s2,n1,n2-1,dp));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return LCS(s1,s2,x-1,y-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends