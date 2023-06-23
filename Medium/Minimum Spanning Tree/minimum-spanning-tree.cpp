//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int V){
        rank.resize(V+1,0);
        parent.resize(V+1);
        size.resize(V+1);
        for(int i=0;i<=V;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findParent(parent[x]);
    }
    // void addEdges(int x,int y){
    //     int boss_parentX=findParent(x);
    //     int boss_parentY=findParent(y);
    //     if(boss_parentX==boss_parentY)return;
    //     if(rank[boss_parentX]==rank[boss_parentY]){
    //         parent[boss_parentY]=boss_parentX;
    //         rank[boss_parentX]++;
    //     }else if(rank[boss_parentX] < rank[boss_parentY]){
    //         parent[boss_parentY]=boss_parentX;
    //     }else{
    //         parent[boss_parentX]=boss_parentY;
    //     }
    // }
    void unionBySize(int x,int y){
        int ulp_x=findParent(x);
        int ulp_y=findParent(y);
        if(ulp_x==ulp_y)return;
        if(size[ulp_x]==size[ulp_y]){
            parent[ulp_y]=ulp_x;
            size[ulp_x]+=size[ulp_y];
        }else if(size[ulp_y] > size[ulp_x]){
            parent[ulp_x]=ulp_y;
            size[ulp_y]+=size[ulp_x];
        }else{
            parent[ulp_y]=ulp_x;
            size[ulp_x]+=size[ulp_y];
        }
    }
};
class Solution
{
	public:
	//Krushkal's Algorithm
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> vec[])
    {
        // code here
        vector<pair<int,pair<int,int>>>adj;
        for(int i=0;i<V;i++){
            for(auto x:vec[i]){
            adj.push_back({x[1],{i,x[0]}});
           }
        }
        
        sort(adj.begin(),adj.end());
        DisjointSet ds(V);
        
        int mst=0;
        for(auto x:adj){
            if(ds.findParent(x.second.first)!=ds.findParent(x.second.second)){
                mst+=x.first;
                ds.unionBySize(x.second.first,x.second.second);
            }
        }
        return mst;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends