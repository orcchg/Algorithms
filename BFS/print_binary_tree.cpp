#include <iostream>
#include <queue>

struct Node {
  char c;
  Node* left;
  Node* right;

  Node(char c): c(c), left(nullptr), right(nullptr) {}
};

/**
     A
    / \
   B   C
  / \   \
 D   E   F

 output:
 A
 B C
 D E F

*/
Node* fillTree() {
  auto a = new Node('A');
  auto b = a->left = new Node('B');
  auto c = a->right = new Node('C');
  b->left = new Node('D');
  b->right = new Node('E');
  c->right = new Node('F');
  return a;
}

void clearTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  clearTree(root->left);
  clearTree(root->right);
  delete root; root = nullptr;
}

void solve(Node* root) {
  std::queue<Node*> q, r;
  q.push(root);

  while (!q.empty()) {
    auto node = q.front();
    std::cout << node->c << ' ';
    q.pop();

    if (node->left != nullptr)  r.push(node->left);
    if (node->right != nullptr) r.push(node->right);

    if (q.empty()) {
      while (!r.empty()) {
        q.push(r.front());
        r.pop();
      }
      std::cout << '\n';
    }
  }
}

int main() {
  auto root = fillTree();
  solve(root);
  clearTree(root);
  return 0;
}

