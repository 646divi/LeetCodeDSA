//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(vector<int>&col,int node,bool graph[101][101],int c,int n){
        for(int k=0;k<n;k++){
            if(k!=node and (graph[k][node]==1) and col[k]==c)return false;
        }
        return true;
    }
    bool colorIT(int node,vector<int>&col,bool graph[101][101],int m,int n){
        if(node==n)return true;
        
        for(int c=1;c<=m;c++){
            if(isSafe(col,node,graph,c,n)){
                col[node]=c;
                if(colorIT(node+1,col,graph,m,n))return true;
                col[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>col(n,0);
        if(colorIT(0,col,graph,m,n))return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends