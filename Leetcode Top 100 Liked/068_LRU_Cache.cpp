class Node {
  public:
  int key;
  int value;
  Node *prev;
  Node *next;

  Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  private:
  int capacity;
  unordered_map<int, Node *> cache;
  Node *oldest;
  Node *latest;

  void remove(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  void insert(Node *node) {
    Node *prev = latest->prev;
    Node *next = latest;
    prev->next = node;
    node->prev = prev;
    node->next = next;
    next->prev = node;
  }

  public:
  LRUCache(int capacity) : capacity(capacity) {
    oldest = new Node(0, 0);
    latest = new Node(0, 0);
    oldest->next = latest;
    latest->prev = oldest;
  }

  ~LRUCache() {
    Node *node = oldest;
    while (node != nullptr) {
      Node *next = node->next;
      delete node;
      node = next;
    }
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];
      remove(node);
      insert(node);
      return node->value;
    }

    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];
      remove(node);
    }

    Node *new_node = new Node(key, value);
    cache[key] = new_node;
    insert(new_node);

    if (cache.size() > capacity) {
      Node *LRU = oldest->next;
      remove(LRU);
      cache.erase(LRU->key);
      delete LRU;
    }
  }
};