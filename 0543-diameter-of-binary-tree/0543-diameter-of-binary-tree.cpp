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
    
    int cal(TreeNode *root,int &maxi){
        if(root==NULL)return 0;
        int left=cal(root->left,maxi);
        int right=cal(root->right,maxi);
        maxi=max(left+right,maxi);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        cal(root,maxi);
        return maxi;
    }
};