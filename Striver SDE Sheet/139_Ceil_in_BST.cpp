int findCeil(Node *root, int input) {
  if (root == NULL)
    return -1;

  Node *curr = root;
  Node *successor = NULL;

  while (curr) {
    if (curr->data < input) {
      curr = curr->right;
    } else if (successor == NULL || (curr->data < successor->data && curr->data >= input)) {
      successor = curr;
      curr = curr->left;
    }
  }

  return (successor != NULL) ? successor->data : -1;
}