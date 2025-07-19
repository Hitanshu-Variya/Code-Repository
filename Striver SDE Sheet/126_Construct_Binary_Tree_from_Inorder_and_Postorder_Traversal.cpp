class Solution {
  private:
  void createMapping(vector<int> &inorder, unordered_map<int, int> &hash_map, int &size) {
    for (int i = 0; i < size; i++) {
      hash_map[inorder[i]] = i;
    }
  }

  TreeNode *solver(int postOrderStart, int postOrderEnd, int inOrderStart, int inOrderEnd, vector<int> &postorder, unordered_map<int, int> &hash_map) {
    if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd) {
      return NULL;
    }

    TreeNode *root = new TreeNode(postorder[postOrderEnd]);

    int index = hash_map[root->val];
    int length = index - inOrderStart;

    root->left = solver(postOrderStart, postOrderStart + length - 1, inOrderStart, index - 1, postorder, hash_map);
    root->right = solver(postOrderStart + length, postOrderEnd - 1, index + 1, inOrderEnd, postorder, hash_map);

    return root;
  }

  public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int size = postorder.size();
    unordered_map<int, int> hash_map;
    createMapping(inorder, hash_map, size);

    TreeNode *root = solver(0, size - 1, 0, size - 1, postorder, hash_map);
    return root;
  }
};