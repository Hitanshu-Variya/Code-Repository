class Solution {
  private:
  int index = 0;

  TreeNode *Build(vector<int> &preorder, int &size, int start, int end) {
    if (index >= size)
      return NULL;

    int value = preorder[index];
    if (value < start || end < value)
      return NULL;

    index++;
    TreeNode *root = new TreeNode(value);
    root->left = Build(preorder, size, start, value);
    root->right = Build(preorder, size, value, end);

    return root;
  }

  public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    int size = preorder.size();
    return Build(preorder, size, INT_MIN, INT_MAX);
  }
};