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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty() && q.front() != NULL){
            q.push(NULL);
            vector<int> level;
            while(q.front() != NULL){
                TreeNode* r = q.front();
                if(r->left)q.push(r->left);
                if(r->right)q.push(r->right);
                level.push_back(r->val);
                q.pop();
            }
            q.pop();
            ans.push_back(level);
        }
        return ans;
    }
};
