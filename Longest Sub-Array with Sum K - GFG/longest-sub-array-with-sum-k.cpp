//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        // Complete the function
        // int max_len=INT_MIN;
        map<int,int>mp;
        // mp[arr[0]]=0;
        int max_len=0;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            //subarray sum equal to K startin from 0th index
            if(sum==K)max_len=max(max_len,(i+1));
            
            
            
            //check if subarray sum exists starting from random index not from 0th
            //i.e check wheather (sum-K) exists or not
            if(mp.find(sum-K)!=mp.end()){
                 max_len=max(max_len,i - mp[sum-K]);
            }
            //always insert curr sum in mp
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return max_len;
        
        
    } 
  

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends