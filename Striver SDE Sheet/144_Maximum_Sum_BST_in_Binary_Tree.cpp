struct Info {
  bool isBST;
  int min;
  int max;
  int sum;
};

class Solution {
  private:
  Info solver(TreeNode *root, int &maxSum) {
    if (root == NULL) {
      return {true, INT_MAX, INT_MIN, 0};
    }

    Info left = solver(root->left, maxSum);
    Info right = solver(root->right, maxSum);

    Info curr;
    curr.sum = left.sum + right.sum + root->val;
    curr.min = min(root->val, left.min);
    curr.max = max(root->val, right.max);
    curr.isBST = left.isBST && right.isBST && (root->val > left.max && root->val < right.min);

    if (curr.isBST) {
      maxSum = max(maxSum, curr.sum);
    }

    return curr;
  }

  public:
  int maxSumBST(TreeNode *root) {
    int maxSum = 0;
    solver(root, maxSum);

    return maxSum;
  }
};