class Solution {
  public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prevGroupEnd = dummy;

    while (true) {
      ListNode *temp = prevGroupEnd;
      for (int i = 0; i < k && temp; i++) {
        temp = temp->next;
      }

      if (!temp)
        break;

      ListNode *groupStart = prevGroupEnd->next;
      ListNode *nextGroupStart = temp->next;

      ListNode *prev = nextGroupStart;
      ListNode *current = groupStart;
      while (current != nextGroupStart) {
        ListNode *front = current->next;
        current->next = prev;
        prev = current;
        current = front;
      }

      prevGroupEnd->next = temp;
      prevGroupEnd = groupStart;
    }

    ListNode *result = dummy->next;
    delete dummy;
    return result;
  }
};