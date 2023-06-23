//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    typedef pair<pair<int,int>,int> p;
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(s.first==d.first and s.second==d.second)return 0;
        // if(grid[d.first][d.second]==0 || grid[s.first][s.second]==0)return -1;
        // int path=0;
        queue<p>q;
        int help[5]={0,-1,0,1,0};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({{s.first,s.second},0});
        dist[s.first][s.second]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int dis=it.second;
            
            // if(row==grid.size()-1 and col==grid[0].size())
            for(int k=0;k<4;k++){
                int nrow=row+help[k];
                int ncol=col+help[k+1];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 and dist[nrow][ncol] > dis+1){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==d.first and ncol==d.second){
                        return dis+1;
                    }
                    q.push({{nrow,ncol},dis+1});
                }
            }
            
        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends