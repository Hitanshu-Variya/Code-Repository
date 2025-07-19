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
  int findMaximumXOR(vector<int> &nums) {
    int size = nums.size();
    int ans = 0;
    Trie trie;

    trie.insert(nums[0]);
    for (int i = 1; i < size; i++) {
      ans = max(ans, trie.getMaxXOR(nums[i]));
      trie.insert(nums[i]);
    }

    return ans;
  }
};
