//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[],int n){
	    int maxi=1;
	    vector<int>temp;
	    temp.push_back(arr[0]);
	    for(int i=1;i<n;i++){
	        if(arr[i]>temp.back()){
	            temp.push_back(arr[i]);
	            maxi++;
	        }else{
	            auto idx=lower_bound(temp.begin(),temp.end(),arr[i]);
	            *idx=arr[i];
	        }
	    }
	    return maxi;
	}
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    if(n==1)return 0;
	    int size=solve(arr,n);
	    return n-size;
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
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends