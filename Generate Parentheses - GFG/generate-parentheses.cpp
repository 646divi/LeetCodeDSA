//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generateAll(vector<string> &ans,int size,int lo,int ro,string str){
        int n=str.length();
        if(n==(size*2)){
            ans.push_back(str);
            return;
        }
        if(lo<size and ro<lo){
            generateAll(ans,size,lo+1,ro,str+'(');
            generateAll(ans,size,lo,ro+1,str+')');
        }
        else if(lo==ro) generateAll(ans,size,lo+1,ro,str+'(');
        else{
            generateAll(ans,size,lo,ro+1,str+')');
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        string str;
        str.push_back('(');
        generateAll(ans,n,1,0,str);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends