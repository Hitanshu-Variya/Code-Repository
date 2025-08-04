class Solution {
  public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = NULL;
    while (slow) {
      ListNode *front = slow->next;
      slow->next = prev;
      prev = slow;
      slow = front;
    }

    ListNode *head1 = head;
    ListNode *head2 = prev;

    while (head1 && head2) {
      if (head1->val != head2->val) {
        return false;
      }

      head1 = head1->next;
      head2 = head2->next;
    }

    return true;
  }
};