//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int,int> p;
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<p> vec;
        for(int i=0;i<n;i++){
            vec.push_back({end[i],start[i]});
        }
        sort(vec.begin(),vec.end());
        
        int lastMeet=vec[0].first;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(lastMeet < vec[i].second){
                lastMeet=vec[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends