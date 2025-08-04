// Using Merge Sort
class Solution {
  private:
  ListNode *Merge(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (left && right) {
      if (left->val < right->val) {
        current->next = left;
        left = left->next;
      } else {
        current->next = right;
        right = right->next;
      }

      current = current->next;
    }

    if (left)
      current->next = left;
    if (right)
      current->next = right;

    ListNode *head = dummy->next;
    delete dummy;
    return head;
  }

  public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *temp = head, *slow = head, *fast = head;
    while (fast && fast->next) {
      temp = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    temp->next = NULL;
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return Merge(left, right);
  }
};

// Using Priority Queue
class Solution {
  public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    auto comparator = [&](ListNode *a, ListNode *b) -> bool {
      return (a->val > b->val);
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(comparator)> pq(comparator);
    
    ListNode *ptr = head;
    while (ptr) {
      ListNode *next = ptr->next;
      ptr->next = NULL;

      pq.push(ptr);
      ptr = next;
    }

    ListNode *dummy = new ListNode(0);
    ptr = dummy;
    while (!pq.empty()) {
      ptr->next = pq.top();
      pq.pop();
      ptr = ptr->next;
    }

    head = dummy->next;
    delete dummy;
    return head;
  }
};