class Solution {
  private:
  bool solver(Node *root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) {
      return true;
    }

    int leftValue = (root->left) ? root->left->data : 0;
    int rightValue = (root->right) ? root->right->data : 0;

    return (leftValue + rightValue == root->data) && solver(root->left) && solver(root->right);
  }

  public:
  int isSumProperty(Node *root) { 
    return (solver(root)) ? 1 : 0; 
  }
};