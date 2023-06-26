//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int long long sum=arr[0];
        int long long max_sum=arr[0];
        for(int i=1;i<n;i++){
            // int temp=sum+arr[i];
            if(sum+arr[i] > arr[i]){
                sum+=arr[i];
            }else{
                sum=arr[i];
            }
            // max_sum=max(sum,max_sum);
            if(max_sum < sum)max_sum=sum;
        }
        return max_sum;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends