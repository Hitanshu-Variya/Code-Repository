class Solution {
  public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        break;
      }
    }
    
    if (!fast || !fast->next)
      return NULL;

    ListNode *slow2 = head;
    while (slow != slow2) {
      slow = slow->next;
      slow2 = slow2->next;
    }

    return slow2;
  }
};