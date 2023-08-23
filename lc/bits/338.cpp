#include <cstdint>
class Solution {

public:
  vector<int> countBits(int n) {
    vector<int> result;
    for (int i = 0; i < n; ++i) {
      result.push_back(hamming(i));
    }
    return result;
  }

private:
  int hamming(uint32_t x) {
    int count = 0;
    while (x) {
      count += x & 1;
      x /= 2;
    }
    return count;
  }
};
