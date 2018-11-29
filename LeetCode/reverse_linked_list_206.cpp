#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* iterative(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 1->2->3->...
        ListNode* node = head->next; head->next = nullptr;
        while (node->next != nullptr) {
          auto last = node->next;
          node->next = head;
          head = node;
          node = last;
        }
        node->next = head;
        return node;
    }
    
    //ListNode* reverseList(ListNode* head) {
    //    return iterative(head);
    //}

    ListNode* recursive(ListNode* prev, ListNode* head) {
        bool needReturn = head->next == nullptr;
        auto last = head->next;
        head->next = prev;
        if (needReturn) return head;
        return recursive(head, last);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto n = recursive(head, head->next);
        head->next = nullptr;
        return n;
    }
};

ListNode* create(int n) {
  ListNode* c = new ListNode(1);
  ListNode* r = c;
  for (int i = 2; i <= n; ++i, r = r->next) {
    r->next = new ListNode(i);
  }
  return c;
}

void print(ListNode* l) {
  while (l != nullptr) {
    std::cout << l->val << "->";
    l = l->next;
  }
}

void clear(ListNode* l) {
  while (l != nullptr) {
    auto x = l;
    l = l->next;
    delete x;
  }
}

int main() {
  Solution s;
  auto input = create(5);
  print(input); std::cout << std::endl;
  auto l = s.reverseList(input);
  print(l); std::cout << std::endl;
  clear(input);
  return 0;
}

