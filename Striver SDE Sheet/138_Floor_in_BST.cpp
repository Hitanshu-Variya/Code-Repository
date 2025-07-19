class Solution {
  public:
  int floor(Node *root, int x) {
    if (root == NULL)
      return -1;

    Node *curr = root;
    Node *predecessor = NULL;

    while (curr) {
      if (curr->data > x) {
        curr = curr->left;
      } else if (predecessor == NULL || (curr->data > predecessor->data && curr->data <= x)) {
        predecessor = curr;
        curr = curr->right;
      }
    }

    return (predecessor != NULL) ? predecessor->data : -1;
  }
};