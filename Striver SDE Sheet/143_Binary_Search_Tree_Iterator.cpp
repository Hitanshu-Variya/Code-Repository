class BSTIterator {
  private:
  vector<TreeNode *> stack;
  TreeNode *ptr;

  public:
  BSTIterator(TreeNode *root) { 
    ptr = root; 
  }

  int next() {
    while (ptr) {
      stack.push_back(ptr);
      ptr = ptr->left;
    }

    TreeNode *node = stack.back();
    stack.pop_back();
    ptr = node->right;

    return node->val;
  }

  bool hasNext() {
    if (!stack.empty() || ptr != NULL) return true;
    return false;
  }
};