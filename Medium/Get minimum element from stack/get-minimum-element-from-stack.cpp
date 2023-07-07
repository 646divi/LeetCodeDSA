//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())return -1;
           return minEle;
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           // now take out the top 
           //if top value is less than or equal to zero 
           //means someone is trying to delete min so our responsibility 
           //is to update new min with previous min;
           if(s.empty()) return -1;
           int tp=s.top();
          s.pop();
           if(tp<=0){
               //to get prev min do
               //minEle -  tp;
               int res=minEle;
               minEle=minEle-tp;
               return res;
           }else return tp;
        //   return tp;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               minEle=x;
               s.push(x);
           }
           //It's time for min to become second i.e prev min
           else if(x<=minEle){
               s.push(x-minEle);
               minEle=x;
           }else{
               s.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends