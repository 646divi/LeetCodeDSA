//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        vector<int>hash(n);
        vector<int>len(n,1);
        sort(arr.begin(),arr.end());
        hash[0]=0;
        int maxi=1;
        int last_idx=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 and len[i] < 1+len[j]){
                    len[i]=1+len[j];
                    hash[i]=j;
                }
            }
            if(len[i] > maxi){
                maxi=len[i];
                last_idx=i;
            }
            
        }
        vector<int>ans;
        ans.push_back(arr[last_idx]);
        while(hash[last_idx]!=last_idx){
            last_idx=hash[last_idx];
            ans.push_back(arr[last_idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends