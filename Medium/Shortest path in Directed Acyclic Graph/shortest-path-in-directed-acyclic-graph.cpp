//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<int>pq;
        pq.push(0);
        vector<int>ans(N,INT_MAX);
        ans[0]=0;
        while(!pq.empty()){
            int node=pq.top();
            pq.pop();
            for(auto x:adj[node]){
                if(ans[x.first] > ans[node]+x.second){
                    ans[x.first]=ans[node]+x.second;
                    pq.push(x.first);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends