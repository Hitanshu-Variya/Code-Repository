class Solution {
  public:
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;

    unordered_map<Node *, Node *> hash_map;
    hash_map[node] = new Node(node->val, {});

    queue<Node *> queue;
    queue.push(node);

    while (!queue.empty()) {
      Node *node = queue.front();
      queue.pop();

      for (auto neighbour : node->neighbors) {
        if (hash_map.find(neighbour) == hash_map.end()) {
          hash_map[neighbour] = new Node(neighbour->val, {});
          queue.push(neighbour);
        }
        hash_map[node]->neighbors.push_back(hash_map[neighbour]);
      }
    }

    return hash_map[node];
  }
};