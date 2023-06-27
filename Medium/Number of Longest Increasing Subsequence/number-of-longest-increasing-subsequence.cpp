//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
        int len=0;
        vector<int>lcs(n,1);
        vector<int>cnt(n,1);
        int l=INT_MIN;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i] and lcs[i] < lcs[j]+1){
	                lcs[i]=1+lcs[j];
	                cnt[i]=cnt[j];
	                
	            }
	            else if(nums[j]<nums[i] and (lcs[i]==lcs[j]+1)){
	                cnt[i]+=cnt[j];
	            }
	        }
	        l=max(l,lcs[i]);
	    }
	   // cout<<l;
	   for(int i=0;i<n;i++){if(lcs[i]==l)len+=cnt[i];}
	    
	    return len;
	    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends