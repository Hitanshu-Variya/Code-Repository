class Solution {
  public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *add = new ListNode(0);
    ListNode *head = add;

    int carry = 0;
    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }

      add->next = new ListNode(carry % 10);
      add = add->next;
      carry /= 10;
    }

    ListNode *dummy = head;
    head = head->next;
    delete dummy;

    return head;
  }
};