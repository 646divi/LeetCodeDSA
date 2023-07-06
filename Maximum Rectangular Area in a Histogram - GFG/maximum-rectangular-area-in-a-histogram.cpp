//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // Naive approach 
        // int area=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int cnt=1;
        //     if(i!=0){
        //         int j;
        //         for(j=i-1;j>=0;j--){
        //             if(arr[j]<arr[i])break;
        //         }
        //         cnt+=(i - j - 1);
                
        //     }
        //     if(i!=n-1){
        //         int j;
        //         for(j=i+1;j<n;j++){
        //             if(arr[j]<arr[i])break;
        //         }
        //         cnt+=(j - i - 1);
        //     }
        //     // area=max(area,(cnt*arr[i]));
        //     int new_area=cnt*arr[i];
        //     if(area < new_area){
        //         area=new_area;
        //     }
        
        //another pproach using 2 aux arrays i.e pse and nse
        // vector<long long>pse(n);
        // vector<long long>nse(n);
        // // pse[0]=0;
        // // nse[n-1]=n;
        // stack<long long>st;
        // // int curr;
        // // st.push(0);
        // for(int i=0;i<n;i++){
        //     while(!st.empty() and arr[i]<=arr[st.top()]){
        //         st.pop();
        //     }
        //     if(st.empty())pse[i]=0;
        //     else pse[i]=st.top()+1;
        //     st.push(i);
            
        // }
        // stack<long long>st2;
        // // st2.push(n-1);
        // for(int i=n-1;i>=0;i--){
        //     while(!st2.empty() and arr[i]<=arr[st2.top()]){
        //         st2.pop();
        //     }
        //     if(st2.empty())nse[i]=n-1;
        //     else nse[i]=st2.top()-1;
        //     st2.push(i);
        // }
        // long long area=0;
        // long long new_area=0;
        // for(int i=0;i<n;i++){
        //     new_area=(nse[i] - pse[i] + 1)*1ll*arr[i];
        //     // new_area*=arr[i];
        //     if(area<new_area)area=new_area;
        // }
        long long area=INT_MIN;
        long long curr=0;
        long long tp;
        stack<long long>st;
        int i=0;
        while(i<n){
            if(st.empty() || arr[st.top()]<=arr[i]){
                st.push(i++);
            }
            else{
                tp=arr[st.top()];
                st.pop();
                curr=tp*((st.empty()==false)?(i-st.top()-1):i);
                if(area<curr)area=curr;
            }
        }
        while(!st.empty()){
            tp=arr[st.top()];
            st.pop();
            curr=tp*((st.empty()==false)?(i-st.top()-1):i);
            if(area<curr)area=curr;
        }
            
        
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends