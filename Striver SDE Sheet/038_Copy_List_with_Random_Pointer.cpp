class Solution {
  public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> hash_map;
    Node *ptr = head;

    while (ptr) {
      hash_map[ptr] = new Node(ptr->val);
      ptr = ptr->next;
    }

    ptr = head;

    while (ptr) {
      Node *copy = hash_map[ptr];
      copy->next = hash_map[ptr->next];
      copy->random = hash_map[ptr->random];
      ptr = ptr->next;
    }

    return hash_map[head];
  }
};