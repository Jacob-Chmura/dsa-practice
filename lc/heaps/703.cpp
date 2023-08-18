#include <algorithm>

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;

    // build a heap of first min(k, nums.size()) elements
    int m = (k < nums.size()) ? k : nums.size();
    for (int i = 0; i < m; ++i)
      heap.push_back(nums[i]);
    build_heap();

    // push the remaining items of nums into the min heap
    for (int i = m; i < nums.size(); ++i)
      add(nums[i]);
  }

  int add(int val) {
    // heap[1] holds current kth largest which we know exists
    if (heap.size() <= k) {
      push(val);
    } else if (val > heap[1]) {
      // we have a new kth largest
      pop();
      push(val);
    }
    return heap[1];
  }

private:
  int k;
  vector<int> heap = {0};
  void build_heap() {
    int n = heap.size() - 1; // we get a dummy element at index 0
    for (int i = n / 2; i > 0; --i) {
      // perc up
      int cur = i;
      while (cur > 1 && heap[cur] < heap[parent(cur)]) {
        std::swap(heap[cur], heap[parent(cur)]);
        cur = parent(cur);
      }
    }
  }
  void pop() {
    // put the last child at the root
    heap[1] = heap.back();
    heap.pop_back();

    // perc down
    int cur = 1;
    while (isvalid(left(cur))) {
      // option 1: swap right
      if (isvalid(right(cur)) && heap[right(cur)] < heap[left(cur)] &&
          heap[right(cur)] < heap[cur]) {
        std::swap(heap[cur], heap[right(cur)]);
        cur = right(cur);
      } else if (heap[left(cur)] < heap[cur]) { // option 2: swap left
        std::swap(heap[cur], heap[left(cur)]);
        cur = left(cur);
      } else { // option 3: no swap, break
        break;
      }
    }
  }
  void push(int val) {
    heap.push_back(val);
    int cur = heap.size() - 1;
    while (cur > 1 && heap[cur] < heap[parent(cur)]) {
      std::swap(heap[cur], heap[parent(cur)]);
      cur = parent(cur);
    }
  }

  int isvalid(int i) { return i <= heap.size(); };
  int left(int i) { return 2 * i; };
  int right(int i) { return 2 * i + 1; };
  int parent(int i) { return i / 2; };
};
