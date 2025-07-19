class Solution {
  private:
  void addLeft(Node *root, vector<int> &ans) {
    Node *curr = root->left;

    while (curr) {
      if (curr->left != NULL || curr->right != NULL) {
        ans.push_back(curr->data);
      }

      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }

  void addLeaf(Node *root, vector<int> &ans) {
    if (root == NULL)
      return;

    if (root->left == NULL && root->right == NULL) {
      ans.push_back(root->data);
    }

    addLeaf(root->left, ans);
    addLeaf(root->right, ans);
  }

  void addRight(Node *root, vector<int> &ans) {
    Node *curr = root->right;
    vector<int> temp;

    while (curr) {
      if (curr->left != NULL || curr->right != NULL) {
        temp.push_back(curr->data);
      }

      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }

    int size = temp.size();
    for (int i = size - 1; i >= 0; i--) {
      ans.push_back(temp[i]);
    }
  }

  public:
  vector<int> boundaryTraversal(Node *root) {
    if (root == NULL) {
      return {};
    }

    vector<int> ans;
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
      return ans;
    }

    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);

    return ans;
  }
};