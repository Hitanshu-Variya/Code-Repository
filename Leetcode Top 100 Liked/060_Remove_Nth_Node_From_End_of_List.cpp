class Solution {
  public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *ptr = new ListNode(0, head);
    ListNode *dummy = ptr;

    for (int i = 0; i < n; i++) {
      head = head->next;
    }

    while (head) {
      head = head->next;
      dummy = dummy->next;
    }

    dummy->next = dummy->next->next;

    head = ptr->next;
    delete ptr;
    return head;
  }
};