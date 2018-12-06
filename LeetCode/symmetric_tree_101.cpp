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
    bool recursive(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        if (root->left == nullptr && root->right != nullptr || root->left != nullptr && root->right == nullptr) {
            return false;
        }
        
        bool good = root->left->val == root->right->val;
        
        if (root->left->left == nullptr && root->right->right != nullptr || 
            root->left->left != nullptr && root->right->right == nullptr ||
            root->left->right == nullptr && root->right->left != nullptr ||
            root->left->right != nullptr && root->right->left == nullptr) {
            return false;
        }
        
        bool sub1 = false;
        if (root->left->left == nullptr && root->right->right == nullptr) {
            sub1 = true;
        } else {
            sub1 = root->left->left->val == root->right->right->val;
        }
        
        bool sub2 = false;
        if (root->left->right == nullptr && root->right->left == nullptr) {
            sub2 = true;
        } else {
            sub2 = root->left->right->val == root->right->left->val;
        }
        
        bool ll = recursive(root->left->left);
        bool lr = recursive(root->left->right);
        bool rl = recursive(root->right->left);
        bool rr = recursive(root->right->right);
        return good && sub1 && sub2 && ll && lr && rl && rr;
    }
    
    bool iterative(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        if (root->left == nullptr && root->right != nullptr || root->left != nullptr && root->right == nullptr) {
            return false;
        }
        
        std::stack<TreeNode*> s;
        std::queue<TreeNode*> q;
        q.push(root);
        s.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            
            if (!s.empty()) {
                if (node->left != nullptr) {
                  if (s.top() == nullptr || s.top()->val != node->left->val) {
                      s.push(node->left);
                  } else {
                      s.pop();
                  }
                } else {
                    if (s.top() == nullptr) {
                        s.pop();
                    } else {
                        s.push(nullptr);
                    }
                }
                if (node->right != nullptr) {
                  if (s.top() == nullptr || s.top()->val != node->right->val) {
                      s.push(node->right);
                  } else {
                      s.pop();
                  }
                } else {
                    if (s.top() == nullptr) {
                        s.pop();
                    } else {
                        s.push(nullptr);
                    }
                }
            }
        }
        
        s.pop();
        return s.empty();
    }
    
    bool isSymmetric(TreeNode* root) {
        return iterative(root);
    }
    
    // [4,4,10,null,-53,-53,null,73,-84,-84,73,-42,null,-84,46,46,-84,null,-42]
};

