class Solution {
  public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> postorder;
    TreeNode *curr = root;

    while (curr != NULL) {
      if (curr->right == NULL) {
        postorder.push_back(curr->val);
        curr = curr->left;
      } else {
        TreeNode *next = curr->right;
        while (next->left && next->left != curr) {
          next = next->left;
        }

        if (next->left == NULL) {
          next->left = curr;
          postorder.push_back(curr->val);
          curr = curr->right;
        } else {
          next->left = NULL;
          curr = curr->left;
        }
      }
    }

    reverse(postorder.begin(), postorder.end());
    return postorder;
  }
};