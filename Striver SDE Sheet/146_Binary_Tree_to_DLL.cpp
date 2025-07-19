// Using Stack Iterator Method
class Solution {
  private:
  vector<Node *> stack;
  Node *head = NULL;

  void solver(Node *root) {
    Node *curr = root;
    Node *prev = NULL;

    while (curr != NULL || !stack.empty()) {
      while (curr) {
        stack.push_back(curr);
        curr = curr->left;
      }

      curr = stack.back();
      stack.pop_back();

      if (head == NULL) {
        head = curr;
      } else {
        curr->left = prev;
        prev->right = curr;
      }

      prev = curr;
      curr = curr->right;
    }
  }

  public:
  Node *bToDLL(Node *root) {
    if (root == NULL) return NULL;
    solver(root);

    return head;
  }
};

// Using Inorder Traversal
class Solution {
  private:
  Node *head = NULL;
  Node *prev = NULL;

  void solver(Node *root) {
    if (root == NULL)
      return;

    solver(root->left);

    if (head == NULL) {
      head = root;
    } else {
      root->left = prev;
      prev->right = root;
    }
    prev = root;

    solver(root->right);
  }

  public:
  Node *bToDLL(Node *root) {
    if (root == NULL) return NULL;
    solver(root);

    return head;
  }
};