class LRUCache {
public:
  class Node {
  public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) : val{val} {};
  };

  LRUCache(int capacity) : capacity{capacity} {};

  int get(int key) {
    if (cache.find(key) == cache.end())
      return -1;

    // get node and remove from lru list
    Node *node = cache[key];
    removeNode(node);

    // put it at the front
    updateNodeTime(node);
    return node->val;
  }

  void put(int key, int value) {
    // create a new node and put it at front
    Node *node = new Node(value);
    updateNodeTime(node);

    // update hash map
    cache[key] = value;

    // evict if needed
    if (cache.size() > capacity) {
      removeLRU();
    }
  }

private:
  int capacity;
  unordered_map<int, Node *> cache;

  // doubly linked list with sentinal nodes
  Node *head = new Node(0);
  Node *tail = new Node(0);
  head->next = tail;
  tail->prev = head;

  void updateNodeTime(Node *node) {
    node->prev = head;
    node->next = head->next;
    head->next = node;
  }

  void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void removeLRU() {
    // get lru node and remove from double linked list
    Node *lru = tail->prev;
    removeNode(lru);

    // remove from hashmap
    cache.erase(lru->val);
    delete lru;
  }
};
