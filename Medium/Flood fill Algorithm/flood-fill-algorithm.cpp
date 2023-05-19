//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void DFS(vector<vector<int>>& image,int n,int m,int i,int j,int c,int prev){
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=prev || image[i][j]==c)return;
        image[i][j]=c;
        DFS(image,n,m,i+1,j,c,prev);
        DFS(image,n,m,i-1,j,c,prev);
        DFS(image,n,m,i,j+1,c,prev);
        DFS(image,n,m,i,j-1,c,prev);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        // vector<vector<int>>vis(n,)
        DFS(image,n,m,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends