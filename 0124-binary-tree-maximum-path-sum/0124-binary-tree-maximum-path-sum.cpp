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
    int calc(TreeNode *root,int &sum){
        if(root==NULL)return 0;
        
        int l=calc(root->left,sum);
        if(l<0)l=0;
        int r=calc(root->right,sum);
        if(r<0)r=0;
        sum=max(sum,(l+r+root->val));
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        calc(root,sum);
        return sum;
    }
};