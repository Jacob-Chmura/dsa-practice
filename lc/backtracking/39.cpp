class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> tmp;
    combinationSumHelper(candidates, result, tmp, target, 0);
    return result;
  }

private:
  void combinationSumHelper(vector<int> &candidates,
                            vector<vector<int>> &result, vector<int> &tmp,
                            int target, int idx) {

    if (target == 0) {
      result.push_back(tmp);
      return;
    }
    if (target < 0 || idx >= candidates.size())
      return;

    // option 1: take i and stay
    tmp.push_back(candidates[idx]);
    combinationSumHelper(candidates, result, tmp, target - candidates[idx],
                         idx);

    // optoin 2: advance
    tmp.pop_back();
    combinationSumHelper(candidates, result, tmp, target, idx + 1);
  }
};
