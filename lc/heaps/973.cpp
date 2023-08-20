#include <queue>

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    // store a min heap of size k, containing k smallest point to origin
    // could do better space by holding max heap if k << n
    vector<vector<int>> triples, result;
    for (auto p : points) {
      triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
    }
    std::priority_queue<vector<int>, vector<vector<int>>,
                        std::greater<vector<int>>>
        pq(triples.begin(), triples.end());
    while (k--) {
      vector<int> x = pq.top();
      pq.pop();
      result.push_back({x[1], x[2]});
    }
    return result;
  };
