//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void generate(vector<int> &c,int tar,vector<vector<int>>&ans,vector<int>&vec,int i){
        if(tar==0){
            ans.push_back(vec);
            return;
        }
        // if(i==c.size()){
        //     if(tar==0){
        //         ans.push_back(vec);
        //         return;
        //     }else return;
        // }
        for(int ind=i;ind<c.size();ind++){
            if(ind > i and c[ind]==c[ind-1])continue;
            if(tar < c[ind])break;
            vec.push_back(c[ind]);
            generate(c,tar-c[ind],ans,vec,ind+1);
            vec.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int> &c, int tar) {
        // Write your code here
        vector<vector<int>>ans;
        vector<int>vec;
        sort(c.begin(),c.end());
        generate(c,tar,ans,vec,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends