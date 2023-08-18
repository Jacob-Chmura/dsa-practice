#include <queue>

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    std::priority_queue<int> pq;
    for (auto stone : stones)
      pq.push(stone);

    int x, y;
    while (pq.size() > 1) {
      y = pq.top();
      pq.pop();
      x = pq.top();
      pq.pop();
      if (x != y)
        pq.push(y - x);
    }
    return (pq.size() == 1) ? pq.top() : 0;
  }
};
