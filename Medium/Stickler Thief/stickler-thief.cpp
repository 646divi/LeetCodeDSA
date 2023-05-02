//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    // Simple recurrsion
    // int solve(int i,int arr[]){
    //     if(i==0)return arr[i];
    //     if(i<0)return 0;
    //     int take=arr[i]+solve(i-2,arr);
    //     int nottake=0+solve(i-1,arr);
    //     return max(take,nottake);
    // }
    
    //Memoization + recurssion TC:O(N), SC:O(N)+O(N)
    // int solve(int i,int arr[],vector<int>&dp){
    //     if(i==0)return arr[i];
    //     if(i<0)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int take=arr[i]+solve(i-2,arr,dp);
    //     int nottake=0+solve(i-1,arr,dp);
    //     return dp[i]=max(take,nottake);
    // }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // return solve(n-1,arr); // case for recurrsion;
        
        //Case when memoization
        /*vector<int>dp(n,-1);
        return solve(n-1,arr,dp);*/
        
        if(n==0)return arr[0];
        vector<int>dp(n,0);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int take=arr[i];if(i>1)take+=dp[i-2];
            int notake=0+dp[i-1];
            dp[i]=max(take,notake);
        }
        return dp[n-1];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends