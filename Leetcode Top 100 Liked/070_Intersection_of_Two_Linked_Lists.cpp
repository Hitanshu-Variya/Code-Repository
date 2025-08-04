class Solution {
  public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return NULL;

    ListNode *startA = headA;
    ListNode *startB = headB;

    while (headA != headB) {
      headA = headA ? headA->next : startB;
      headB = headB ? headB->next : startA;
    }

    return headA;
  }
};