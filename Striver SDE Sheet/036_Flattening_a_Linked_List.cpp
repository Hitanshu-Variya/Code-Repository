class Solution {
  public:
  Node *flatten(Node *root) {
    auto comparator = [&](Node *a, Node *b) -> bool {
      return a->data > b->data;
    };

    priority_queue<Node*, vector<Node*>, decltype(comparator)> pq(comparator);

    Node *ptr = root;
    while (ptr) {
      pq.push(ptr);
      ptr = ptr->next;
    }

    Node *dummy = new Node(0);
    Node *dummy_ptr = dummy;

    while (!pq.empty()) {
      Node *node = pq.top();
      pq.pop();

      dummy_ptr->bottom = node;
      dummy_ptr = node;

      if (node->bottom) {
        pq.push(node->bottom);
      }
    }

    Node *head = dummy->bottom;
    delete dummy;
    return head;
  }
};