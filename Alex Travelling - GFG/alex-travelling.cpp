//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef pair<int,int> p;
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        // int n1=flights.size();
        vector<pair<int,int>> adj[n];
        for(auto x:flights){
            adj[x[0]-1].push_back({x[1]-1,x[2]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({k-1,0});
        dist[k-1]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            int cst=it.second;
            for(auto x:adj[node]){
                int nnode=x.first;
                int cost=x.second;
                if(dist[nnode] > cost+cst){
                    dist[nnode]=cost+cst;
                    pq.push({nnode,dist[nnode]});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)ans=max(ans,dist[i]);
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends