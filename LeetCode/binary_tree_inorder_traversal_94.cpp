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
    void solve(vector<int>& res, TreeNode* root) {
        if (root == nullptr) return;
        
        solve(res, root->left);
        res.push_back(root->val);
        solve(res, root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(res, root);
        return res;
    }
};
