//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        string ans="";
        stack<char>st;
        for(int x=0;x<S.size();x++){
            while(!st.empty() and k>0 and st.top()>S[x]){
                st.pop();
                k-=1;
            }
            if(!st.empty() || S[x]!='0'){
                st.push(S[x]);
            }
        }
        //remove the elements left in stack why? consider example 1 2 3 everything is in  
        //asc order so we need to deelete the last k elements
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends