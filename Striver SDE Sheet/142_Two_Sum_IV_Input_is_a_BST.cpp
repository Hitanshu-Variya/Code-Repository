class Solution {
  public:
  bool findTarget(TreeNode *root, int k) {
    bool ans = false;
    unordered_set<int> set;

    function<void(TreeNode *, int &)> inorder = [&](TreeNode *root, int &k) -> void {
      if (root == NULL) return;

      inorder(root->left, k);

      if (set.find(k - root->val) != set.end()) ans = true;
      set.insert(root->val);
      
      inorder(root->right, k);
    };

    inorder(root, k);
    return ans;
  }
};