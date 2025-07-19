struct Node {
  vector<Node *> links = vector<Node *>(26, nullptr);
  int wordEnd = 0;
  int prefixEnd = 0;

  bool containsKey(char ch) { 
    return links[ch - 'a'] != nullptr; 
  }

  void put(char ch, Node *node) { 
    links[ch - 'a'] = node; 
  }

  Node *get(char ch) { 
    return links[ch - 'a']; 
  }

  int getPrefixEnd() { 
    return prefixEnd; 
  }

  void incrementPrefixEnd() { 
    prefixEnd++; 
  }

  void decrementPrefixEnd() {
    if (prefixEnd == 0) return;
    prefixEnd--;
  }

  int getWordEnd() { 
    return wordEnd; 
  }

  void incrementWordEnd() { 
    wordEnd++; 
  }

  void decrementWordEnd() {
    if (wordEnd == 0) return;
    wordEnd--;
  }
};

class Trie {
  private:
  Node *root;

  public:
  Trie() { 
    root = new Node(); 
  }

  void insert(string &word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        node->put(character, new Node());
      }
      node = node->get(character);
      node->incrementPrefixEnd();
    }
    node->incrementWordEnd();
  }

  int countWordsEqualTo(string &word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        return 0;
      }
      node = node->get(character);
    }
    return node->getWordEnd();
  }

  int countWordsStartingWith(string &word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        return 0;
      }
      node = node->get(character);
    }
    return node->getPrefixEnd();
  }

  void erase(string &word) {
    Node *node = root;
    for (auto &character : word) {
      if (!node->containsKey(character)) {
        return;
      }
      node = node->get(character);
      node->decrementPrefixEnd();
    }
    node->decrementWordEnd();
  }
};