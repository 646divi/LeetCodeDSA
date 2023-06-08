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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    flag=1;
                 }
                if(temp->right){
                    q.push(temp->right);
                    flag=1;
                 }
                sum+=temp->val;
            }
            if(!flag){
                break;
            }else{
                flag=0;
                sum=0;
            }
            
            
        }
        return sum;
        
    }
};