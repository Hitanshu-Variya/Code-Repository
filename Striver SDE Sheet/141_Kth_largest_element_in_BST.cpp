class Solution {
  public:
  int kthLargest(Node *root, int k) {
    int count = 0, ans = -1;
    function<void(Node *)> inorder = [&](Node *root) -> void {
      if (root == NULL) return;

      inorder(root->right);

      count++;
      if (count == k) ans = root->data;

      inorder(root->left);
    };

    inorder(root);
    return ans;
  }
};