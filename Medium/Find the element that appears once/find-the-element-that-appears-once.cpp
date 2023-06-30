//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    if(n==1)return arr[0];
	    if(arr[0]!=arr[1])return arr[0];
	    if(arr[n-2]!=arr[n-1])return arr[n-1];
	    int low=0;
	    int high=n-1;
	    while(low<=high){
	        int mid=(low+high)>>1;
	        if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1])return arr[mid];
	        else if(arr[mid]!=arr[mid-1] and mid%2==0 || arr[mid]!=arr[mid+1] and mid%2==1)low=mid+1;
	        else high=mid-1;
	    }
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends