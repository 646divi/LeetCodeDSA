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
    TreeNode * build(vector<int>& p,int ub,int &i){
        if(i==p.size() || p[i]>ub)return NULL;
        TreeNode * root=new TreeNode(p[i++]);
        root->left=build(p,root->val,i);
        root->right=build(p,ub,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==1){
            return new TreeNode(preorder[0]);
        }
        int i=0;
        return build(preorder,INT_MAX,i);
    }
};