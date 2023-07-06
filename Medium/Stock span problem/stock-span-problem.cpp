//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       //brute force O(N^2) and constant space
    //   vector<int>ans;
    //   ans.push_back(1);
    //   for(int i=1;i<n;i++){
    //       int cnt=1;
    //       for(int j=i-1;j>=0;j--){
    //           if(price[i]<=price[j])break;
    //           cnt++;
    //       }
    //       ans.push_back(cnt);
    //   }
    //   return ans;
        vector<int>ans;
        stack<int>st;
        //stack based approach which will use O(N) space
        //this concept is based on consecutive previous greater element
        // as we know for the first element stock span will always be one
        // so push the index of first element
        // Now start from 1st and check if top is smaller than or equal to curr if yes keep on popping element 
        //from the stack and once the stack becomes empty or st.top() becomes greater just 
        //ans.push_back(i-st.top());
        st.push(0);
        ans.push_back(1);
        for(int i=1;i<n;i++){
            while(!st.empty() and price[st.top()]<=price[i]){
                st.pop();
            }
            if(st.empty())ans.push_back(i+1);
            else ans.push_back(i - st.top());
            st.push(i);
        }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends