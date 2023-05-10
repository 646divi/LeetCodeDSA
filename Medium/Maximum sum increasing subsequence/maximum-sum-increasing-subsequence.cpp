//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    if(n==1)return arr[0];
	    vector<int>lis(n);
	   // int maxi=0;
	    for(int i=0;i<n;i++){
	        lis[i]=arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                lis[i]=max(lis[i],arr[i]+lis[j]);
	            }
	           // maxi=max(maxi,lis[i]);
	        }
	    }
	   // return maxi;
	   return *max_element(lis.begin(), lis.end());
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends