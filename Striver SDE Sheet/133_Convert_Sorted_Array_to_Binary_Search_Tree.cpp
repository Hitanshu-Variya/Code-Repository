class Solution {
  private:
  TreeNode *solver(vector<int> &nums, int start, int end) {
    if (start > end) {
      return NULL;
    }

    int mid = (end + start + 1) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = solver(nums, start, mid - 1);
    root->right = solver(nums, mid + 1, end);

    return root;
  }

  public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int size = nums.size();
    TreeNode *root = solver(nums, 0, size - 1);

    return root;
  }
};