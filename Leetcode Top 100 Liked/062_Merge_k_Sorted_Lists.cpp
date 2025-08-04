class Solution {
  public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comparator = [&](ListNode *a, ListNode *b) -> bool {
      return a->val > b->val;
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(comparator)> pq(comparator);
    ListNode *dummy = new ListNode(0);
    ListNode *root = dummy, *ptr = dummy;

    for (ListNode *node : lists) {
      if (node == NULL)
        continue;
      pq.push(node);
    }

    if (pq.size() == 0) {
      return NULL;
    }

    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      ptr->next = node;
      ptr = ptr->next;

      ListNode *next = node->next;
      node->next = NULL;

      if (next) {
        pq.push(next);
      }
    }

    ListNode *head = root->next;
    delete dummy;
    return head;
  }
};