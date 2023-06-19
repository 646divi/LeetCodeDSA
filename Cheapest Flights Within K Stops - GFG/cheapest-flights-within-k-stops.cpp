//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<pair<int,int>,int>>q;
        // K+=1;
        q.push({{src,0},0});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first.first;
            int dis=it.first.second;
            int k=it.second;
            if(k>K)continue;
            for(auto x:adj[node]){
                int nnode=x.first;
                int dis2=x.second;
                if(dist[nnode] > dis2+dis){
                    dist[nnode]=dis2+dis;
                    q.push({{nnode,dist[nnode]},k+1});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends