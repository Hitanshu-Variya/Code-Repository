class Node {
  public:
  int key, value, freq;
  Node *prev;
  Node *next;

  Node(int key, int value) : key(key), value(value) {
    freq = 1;
    prev = NULL;
    next = NULL;
  }
};

class LinkedList {
  public:
  int size;
  Node *oldest;
  Node *latest;

  LinkedList() {
    latest = new Node(-1, -1);
    oldest = new Node(-1, -1);
    oldest->next = latest;
    latest->prev = oldest;
    size = 0;
  }

  void insert(Node *node) {
    Node *prev = latest->prev;
    Node *next = latest;
    prev->next = node;
    node->prev = prev;
    node->next = next;
    next->prev = node;
    size++;
  }

  void remove(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
    size--;
  }
};

class LFUCache {
  private:
  unordered_map<int, Node *> keyNode;
  unordered_map<int, LinkedList *> freqMap;
  int capacity, size, minFreq;

  void updateFreqMap(Node *node) {
    keyNode.erase(node->key);
    LinkedList *DLL = freqMap[node->freq];
    DLL->remove(node);

    if (node->freq == minFreq && DLL->size == 0) {
      minFreq++;
    }

    LinkedList *newDLL;
    if (freqMap.find(node->freq + 1) != freqMap.end()) {
      newDLL = freqMap[node->freq + 1];
    } else {
      newDLL = new LinkedList();
    }

    node->freq++;
    newDLL->insert(node);
    keyNode[node->key] = node;
    freqMap[node->freq] = newDLL;
  }

  public:
  LFUCache(int capacity) : capacity(capacity) {
    size = 0;
    minFreq = 0;
  }

  int get(int key) {
    if (keyNode.find(key) != keyNode.end()) {
      Node *node = keyNode[key];
      int value = node->value;
      updateFreqMap(node);
      return value;
    }

    return -1;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;

    if (keyNode.find(key) != keyNode.end()) {
      Node *node = keyNode[key];
      node->value = value;
      updateFreqMap(node);
      return;
    }

    if (size == capacity) {
      LinkedList *DLL = freqMap[minFreq];
      Node *toBeDeleted = DLL->oldest->next;
      DLL->remove(toBeDeleted);
      keyNode.erase(toBeDeleted->key);
      delete toBeDeleted;
      size--;
    }

    minFreq = 1;
    size++;

    LinkedList *newDLL;
    if (freqMap.find(minFreq) != freqMap.end()) {
      newDLL = freqMap[minFreq];
    } else {
      newDLL = new LinkedList();
    }

    Node *node = new Node(key, value);
    newDLL->insert(node);
    keyNode[node->key] = node;
    freqMap[minFreq] = newDLL;
  }
};