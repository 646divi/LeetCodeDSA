//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(vector<int> adj[],vector<int>&vis,int s){
        vis[s]=1;
        for(auto x:adj[s]){
            if(!vis[x])DFS(adj,vis,x);
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adj2[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j])adj2[i].push_back(j);
            }
        }
        int ans=0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                DFS(adj2,vis,i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends