//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int max_len=0;
        int i=0,j=0;
        int flip=0;
        while(i<n){
            if(arr[i]==0)flip++;
            while(flip>m){
                if(arr[j]==0)flip--;
                j++;
            }
            max_len=max(max_len,i-j+1);
            i++;
        }
        return max_len;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends