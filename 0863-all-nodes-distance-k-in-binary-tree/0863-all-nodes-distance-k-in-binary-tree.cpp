/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void updateTree(TreeNode* root,unordered_map<TreeNode *,TreeNode *>&parent){
       queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();q.pop();
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        // if(root==NULL)return ans;
        unordered_map<TreeNode *,TreeNode *>parent;
        unordered_map<TreeNode *,bool>vis;
        updateTree(root,parent);
        
        int dis=0;
        queue<TreeNode *>q;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            int size=q.size();
            if(dis++ == k)break;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left and !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right and !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(parent[temp] and !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=true;
                }
            }
            
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};