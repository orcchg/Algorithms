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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> s, r;
        int h = 0;
        if (root != nullptr) {
            s.push(root);
        }
        while (!s.empty()) {
            auto node = s.front();
            s.pop();
            
            if (node->left != nullptr) {
                r.push(node->left);
            }
            if (node->right != nullptr) {
                r.push(node->right);
            }
            
            if (s.empty()) {
                ++h;
                while (!r.empty()) {
                    s.push(r.front());
                    r.pop();
                }
            }
        }
        return h;
    }
};

