// Using Manual Memory Deletion
struct Node {
  vector<Node *> links = vector<Node *>(26, nullptr);
  ~Node() {
    for (auto link : links) {
      if (link) {
        delete link;
      }
    }
  }

  bool containsKey(char ch) { 
    return links[ch - 'a'] != nullptr; 
  }

  void put(char ch, Node *node) { 
    links[ch - 'a'] = node; 
  }

  Node *get(char ch) { 
    return links[ch - 'a']; 
  }
};

int countDistinctSubstring(string s) {
  int size = s.size();
  int count = 0;

  Node *root = new Node();

  for (int i = 0; i < size; i++) {
    Node *node = root;
    for (int j = i; j < size; j++) {
      if (!node->containsKey(s[j])) {
        count++;
        node->put(s[j], new Node());
      }
      node = node->get(s[j]);
    }
  }

  delete root;
  return count + 1;
}

// Using Smart Unique Pointers in c++
struct Node {
  vector<unique_ptr<Node>> links = vector<unique_ptr<Node>>(26);

  bool containsKey(char ch) { 
    return links[ch - 'a'] != nullptr; 
  }

  void put(char ch, unique_ptr<Node> node) { 
    links[ch - 'a'] = move(node); 
  }

  Node *get(char ch) { 
    return links[ch - 'a'].get(); 
  }
};

int countDistinctSubstring(string s) {
  int size = s.size();
  int count = 0;

  auto root = make_unique<Node>();

  for (int i = 0; i < size; i++) {
    Node *node = root.get();
    for (int j = i; j < size; j++) {
      if (!node->containsKey(s[j])) {
        count++;
        node->put(s[j], make_unique<Node>());
      }
      node = node->get(s[j]);
    }
  }

  return count + 1;
}