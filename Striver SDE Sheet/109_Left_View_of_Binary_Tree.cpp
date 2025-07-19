class Solution {
  public:
  vector<int> leftView(Node *root) {
    vector<int> ans;
    int depth = 0, max_depth = 0;

    function<void(Node *, int)> solver = [&](Node *root, int depth) -> void {
      if (root == NULL)
        return;

      if (max_depth == depth) {
        ans.push_back(root->data);
        max_depth++;
      }

      solver(root->left, depth + 1);
      solver(root->right, depth + 1);
    };

    solver(root, depth);
    return ans;
  }
};