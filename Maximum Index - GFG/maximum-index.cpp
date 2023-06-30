//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            if(arr[st.top()]>=arr[i]){
                st.push(i);
            }
        }
        int max_len=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int curr=0;
            while(!st.empty() and arr[st.top()]<=arr[i]){
                int j=st.top();st.pop();
                curr=i-j;
                max_len=max(max_len,curr);
            }
        }
        return max_len;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends