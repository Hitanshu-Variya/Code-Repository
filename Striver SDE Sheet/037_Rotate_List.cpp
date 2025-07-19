class Solution {
  public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0)
      return head;

    ListNode *ptr = head;
    int size = 1;

    while (ptr->next) {
      ptr = ptr->next;
      size++;
    }

    k = k % size;
    if (k == 0)
      return head;

    // Build up a Cycle
    ptr->next = head;
    int forward = size - k;

    ListNode *dummy_ptr = ptr;
    while (forward--) {
      dummy_ptr = dummy_ptr->next;
    }

    ListNode *root = dummy_ptr->next;
    dummy_ptr->next = NULL;
    return root;
  }
};