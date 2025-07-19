struct Node {
  vector<Node *> link = vector<Node *>(2, nullptr);

  bool containsKey(int bit) { 
    return (link[bit] != nullptr); 
  }

  void put(int bit, Node *node) { 
    link[bit] = node; 
  }

  Node *get(int bit) { 
    return link[bit]; 
  }
};

class Trie {
  private:
  Node *root;

  public:
  Trie() { 
    root = new Node(); 
  }

  void insert(int num) {
    Node *node = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      if (!node->containsKey(bit)) {
        node->put(bit, new Node());
      }
      node = node->get(bit);
    }
  }

  int getMaxXOR(int num) {
    Node *node = root;
    int maxXOR = 0;
    for (int i = 31; i >= 0; i--) {
      int reqbit = 1 - ((num >> i) & 1);
      if (!node->containsKey(reqbit)) {
        node = node->get(1 - reqbit);
      } else {
        maxXOR = maxXOR | (1 << i);
        node = node->get(reqbit);
      }
    }

    return maxXOR;
  }
};

class Solution {
  public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    int size = queries.size();
    vector<vector<int>> offlineQueries;

    for (int i = 0; i < size; i++) {
      offlineQueries.push_back({queries[i][1], queries[i][0], i});
    }

    sort(offlineQueries.begin(), offlineQueries.end());
    sort(nums.begin(), nums.end());

    Trie trie;
    vector<int> ans(size, -1);
    size = nums.size();
    int idx = 0;

    for (auto query : offlineQueries) {
      int limit = query[0], num = query[1], index = query[2];

      while (idx < size && nums[idx] <= limit) {
        trie.insert(nums[idx]);
        idx++;
      }

      if (idx == 0)
        ans[index] = -1;
      else
        ans[index] = trie.getMaxXOR(num);
    }

    return ans;
  }
};