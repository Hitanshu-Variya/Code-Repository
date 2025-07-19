class Codec {
  public:
  string serialize(TreeNode *root) {
    string encode = "";
    if (root == NULL) return encode;

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();

      if (node == NULL) {
        encode.append("#,");
      } else {
        encode.append(to_string(node->val) + ",");
        queue.push(node->left);
        queue.push(node->right);
      }
    }

    return encode;
  }

  TreeNode *deserialize(string data) {
    if (data == "") return NULL;
    stringstream ss(data);
    string value;

    getline(ss, value, ',');
    TreeNode *root = new TreeNode(stoi(value));

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();

      getline(ss, value, ',');
      if (value == "#")
        node->left = NULL;
      else {
        node->left = new TreeNode(stoi(value));
        queue.push(node->left);
      }

      getline(ss, value, ',');
      if (value == "#")
        node->right = NULL;
      else {
        node->right = new TreeNode(stoi(value));
        queue.push(node->right);
      }
    }

    return root;
  }
};