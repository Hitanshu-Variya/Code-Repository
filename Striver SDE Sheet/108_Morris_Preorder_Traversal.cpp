class Solution {
  public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> preorder;
    TreeNode *curr = root;

    while (curr != NULL) {
      if (curr->left == NULL) {
        preorder.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode *next = curr->left;
        while (next->right && next->right != curr) {
          next = next->right;
        }

        if (next->right == NULL) {
          next->right = curr;
          preorder.push_back(curr->val);
          curr = curr->left;
        } else {
          next->right = NULL;
          curr = curr->right;
        }
      }
    }

    return preorder;
  }
};