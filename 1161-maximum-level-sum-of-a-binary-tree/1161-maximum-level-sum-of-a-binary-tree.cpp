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
    int maxLevelSum(TreeNode* root) {
        if(!root->left and !root->right)return 1;
        int lvl=0;
        int curr_lvl=0;
        int sum=INT_MIN;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            curr_lvl++;
            int size=q.size();
            int s=0;
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                s+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(sum<s){
                sum=s;
                lvl=curr_lvl;
            }
        }
        return lvl;
    }
};