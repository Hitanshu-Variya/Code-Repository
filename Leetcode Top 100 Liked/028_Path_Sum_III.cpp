using i64 = long long int;
class Solution {
  public:
  int pathSum(TreeNode *root, int targetSum) {
    i64 count = 0, target = static_cast<i64>(targetSum);
    unordered_map<i64, i64> hashMap;
    hashMap[0] = 1;

    function<void(TreeNode *, i64)> DFS = [&](TreeNode *root, i64 sum) -> void {
      if (root == NULL) {
        return;
      }

      sum += static_cast<i64>(root->val);
      count += hashMap[sum - target];

      hashMap[sum]++;
      DFS(root->left, sum);
      DFS(root->right, sum);
      hashMap[sum]--;
    };

    DFS(root, 0);
    return static_cast<int>(count);
  }
};