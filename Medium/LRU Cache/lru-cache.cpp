//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    class Node
    {
        public:
        int val;int key;
        Node * next;
        Node * prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    public:
    
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int capi;
    unordered_map<int,Node*>mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capi=cap;
        head->next=tail;
        tail->prev=head;
        // code here
    }
    void addNode(Node* node){
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
    }
    void deleteNode(Node *delnode){
        Node *delp=delnode->prev;
        Node *deln=delnode->next;
        delp->next=deln;
        deln->prev=delp;
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            int res=node->val;
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key]=head->next;
            return res;
        }else{
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if(mp.size()==capi){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends