class Solution {
public:
  int guessNumber(int n) {
    int l = 0, r = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int result = guess(m);
      if (result == 1)
        l = m + 1;
      else if (result == -1)
        r = m - 1;
      else
        return m;
    }
    return -1;
  }
};
