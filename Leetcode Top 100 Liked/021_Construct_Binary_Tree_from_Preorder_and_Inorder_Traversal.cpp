class Solution {
  private:
  void createMapping(vector<int> &inorder, unordered_map<int, int> &hash_map, int &size) {
    for (int i = 0; i < size; i++) {
      hash_map[inorder[i]] = i;
    }
  }

  TreeNode *solver(int preOrderStart, int preOrderEnd, int InOrderStart, int InOrderEnd, vector<int> &preorder, unordered_map<int, int> &hash_map) {
    if (preOrderStart > preOrderEnd || InOrderStart > InOrderEnd) {
      return NULL;
    }

    int value = preorder[preOrderStart];
    TreeNode *root = new TreeNode(value);
    int element = hash_map[root->val];
    int elementLeft = hash_map[root->val] - InOrderStart;

    root->left = solver(preOrderStart + 1, preOrderStart + elementLeft, InOrderStart, element - 1, preorder, hash_map);
    root->right = solver(preOrderStart + elementLeft + 1, preOrderEnd, element + 1, InOrderEnd, preorder, hash_map);

    return root;
  }

  public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size();
    unordered_map<int, int> hash_map;
    createMapping(inorder, hash_map, size);

    TreeNode *root = solver(0, size - 1, 0, size - 1, preorder, hash_map);
    return root;
  }
};