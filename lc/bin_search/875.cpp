#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(begin(piles), end(piles));
    while (l < r) {
      int m = l + (r - l) / 2;
      if (canFinishAtSpeed(piles, h, m))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  bool canFinishAtSpeed(vector<int> &piles, int h, int k) {
    for (int i = 0; i < piles.size(); ++i) {
      h -= (piles[i] + k - 1) / k;
      if (h < 0)
        return false;
    }
    return true;
  }
};
