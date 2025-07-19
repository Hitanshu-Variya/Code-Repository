// Usual Solution
class Solution {
  public:
  int kthSmallest(TreeNode *root, int k) {
    int count = 0;
    int ans = -1;

    function<void(TreeNode *)> inorder = [&](TreeNode *root) -> void {
      if (root == NULL) return;

      inorder(root->left);

      count++;
      if (count == k) ans = root->val;
      
      inorder(root->right);
    };

    inorder(root);
    return ans;
  }
};

// Follow Up Solution
struct TreeNode {
  int val;
  int size;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  private:
  int Build(TreeNode *root) {
    if (root == NULL) return 0;
    root->size = Build(root->left) + Build(root->right) + 1;
    return root->size;
  }

  int getkthSmallest(TreeNode *root, int k) {
    int leftNodes = (root->left) ? root->left->size : 0;

    if (k == leftNodes + 1) return root->val;
    else if (k <= leftNodes) return getkthSmallest(root->left, k);
    else return getkthSmallest(root->right, k - leftNodes - 1);
  }

  public:
  int kthSmallest(TreeNode *root, int k) {
    Build(root);
    return getkthSmallest(root, k);
  }
};