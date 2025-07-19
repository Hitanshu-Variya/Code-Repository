class Solution {
  private:
  Node *getPredecessor(Node *root, int &key) {
    if (root == NULL) return NULL;
    Node *predecessor = NULL;

    while (root) {
      if (root->data >= key) {
        root = root->left;
      } else if (predecessor == NULL || (root->data > predecessor->data && root->data < key)) {
        predecessor = root;
        root = root->right;
      }
    }

    return predecessor;
  }

  Node *getSuccessor(Node *root, int &key) {
    if (root == NULL) return NULL;
    Node *successor = NULL;

    while (root) {
      if (root->data <= key) {
        root = root->right;
      } else if (successor == NULL || (root->data < successor->data && root->data > key)) {
        successor = root;
        root = root->left;
      }
    }

    return successor;
  }

  public:
  vector<Node *> findPreSuc(Node *root, int key) {
    vector<Node*> ans = {getPredecessor(root, key), getSuccessor(root, key)};
    return ans;
  }
};