//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i=0,j=0;
        int len=0;
        int dis=0;
        unordered_map<int,int>mp;
        while(i<N){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0)mp.erase(fruits[j]);
                j++;
            }
            len=max(len, i - j + 1);
            i++;
            
            // mp[fruits[i]]++;
            
        }
        
        return len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends