#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // just do bin search treating matrix as c-order array
    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m * n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (getAtIndex(matrix, n, mid) < target)
        l = mid + 1;
      else if (getAtIndex(matrix, n, mid) > target)
        r = mid - 1;
      else
        return true;
    }
    return false;
  }

private:
  int getAtIndex(vector<vector<int>> &matrix, int n, int idx) {
    int row = idx % n;
    int col = idx / n;
    return matrix[row][col];
  }
};
