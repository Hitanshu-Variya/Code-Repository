// Using Traversal
class Solution {
  public:
  Node *connect(Node *root) {
    if (root == NULL)
      return root;

    Node *leftNode = root;
    while (leftNode->left) {
      Node *current = leftNode;

      while (current) {
        current->left->next = current->right;
        if (current->next) {
          current->right->next = current->next->left;
        }

        current = current->next;
      }

      leftNode = leftNode->left;
    }

    return root;
  }
};

// Using Queue
class Solution {
  public:
  Node *connect(Node *root) {
    if (root == NULL) {
      return NULL;
    }

    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();
      Node *back = NULL, *front = NULL;

      for (int i = 0; i < size; i++) {
        Node *node = queue.front();
        queue.pop();

        if (i == 0)
          back = node;
        else {
          front = node;
          back->next = front;
          back = front;
        }

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
    }

    return root;
  }
};