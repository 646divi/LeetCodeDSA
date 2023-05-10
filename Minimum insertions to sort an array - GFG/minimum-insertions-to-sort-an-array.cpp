//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[],int n){
	    vector<int>lis(n,1);
	    int maxi=0;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<=arr[i]){
	                lis[i]=max(lis[i],1+lis[j]);
	            }
	            maxi=max(maxi,lis[i]);
	        }
	    }
	    return n-maxi;
	}
	int minInsertions(int arr[], int n) 
	{ 
	    // Your code goes here
	    if(n==1)return 0;
	    return solve(arr,n);
	   // return n-size;
	} 
};


//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	   

	    Solution ob;
	    cout << ob.minInsertions(arr, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends