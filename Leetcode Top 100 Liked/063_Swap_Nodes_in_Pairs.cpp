class Solution {
  private:
  ListNode *solver(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *start = head;
    ListNode *end = head->next;
    ListNode *next = end->next;

    end->next = start;
    start->next = solver(next);

    return end;
  }

  public:
  ListNode *swapPairs(ListNode *head) { 
    return solver(head); 
  }
};