/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree2(vector<int>& inorder,int ins,int ine,vector<int>& postorder,int pos,int poe,map<int,int>&mp){
        if(pos>poe || ins>ine)return NULL;
        TreeNode *root=new TreeNode(postorder[poe]);
        int idx=mp[postorder[poe]];
        int Llimit=idx-ins;
        root->left=buildTree2(inorder,ins,idx-1,postorder,pos, pos+Llimit-1,mp);
        root->right=buildTree2(inorder,idx+1,ine,postorder,pos+Llimit,poe-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())return NULL;
        int n=inorder.size();
        // int ins=0,pos=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return buildTree2(inorder,0,n-1,postorder,0,n-1,mp);
    }
};