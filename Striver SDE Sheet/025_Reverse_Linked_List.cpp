class Solution {
  public:
  ListNode* reverseList(ListNode *head) {
      ListNode *prev = NULL;
      ListNode *front = NULL;

      while(head) {
          front = head->next;
          head->next = prev;
          prev = head;
          head = front;
      }

      return prev;
  }
};