struct Node {
  vector<Node*> links = vector<Node*>(26, nullptr);
  bool flag = false;

  bool containsKey(char ch) { 
    return links[ch - 'a'] != nullptr; 
  }

  void put(char ch, Node *node) { 
    links[ch - 'a'] = node; 
  }

  Node *get(char ch) { 
    return links[ch - 'a']; 
  }

  void setEnd() { 
    flag = true; 
  }

  bool isEnd() { 
    return flag; 
  }
};

class Trie {
  private:
  Node *root;

  public:
  Trie() { 
    root = new Node(); 
  }

  void insert(string word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        node->put(character, new Node());
      }
      node = node->get(character);
    }
    node->setEnd();
  }

  bool search(string word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        return false;
      }
      node = node->get(character);
    }
    return node->isEnd();
  }

  bool startsWith(string prefix) {
    Node *node = root;
    for (auto &character : prefix) {
      if (!node->containsKey(character)) {
        return false;
      }
      node = node->get(character);
    }
    return true;
  }
};