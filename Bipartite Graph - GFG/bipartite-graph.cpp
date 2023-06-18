//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int vis[],int col[],vector<int> adj[],int node,int colr){
        vis[node]=1;
        col[node]=colr;
        for(auto x:adj[node]){
            if(!vis[x] and !dfs(vis,col,adj,x,!colr))return false;
            else if(col[node]==col[x])return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int vis[V]={0};
	    int col[V];
	    int colr=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i] and !dfs(vis,col,adj,i,colr))return false;
	        colr=!colr;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends