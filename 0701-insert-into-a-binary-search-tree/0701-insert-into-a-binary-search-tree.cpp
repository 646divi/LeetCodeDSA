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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        // if(val < root->val ){
        //     root->left=insertIntoBST(root->left,val);
        // }
        // if(val > root->val){
        //     root->right=insertIntoBST(root->right,val);
        // }
        // return root;
        TreeNode *curr=root;
        while(curr){
            if(val > curr->val){
                if(curr->right){
                    curr=curr->right;
                }else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            if(val < curr->val){
                if(curr->left){
                    curr=curr->left;
                }else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};