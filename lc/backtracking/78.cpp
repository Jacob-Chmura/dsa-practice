#import <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> sets;
    vector<int> set;
    subset_helper(sets, set, nums, 0);
    return sets;
  }

private:
  void subset_helper(vector<vector<int>> &sets, vector<int> &set,
                     vector<int> &nums, int idx) {
    sets.push_back(set);
    for (int i = idx; i < nums.size(); ++i) {
      set.push_back(nums[i]);
      subset_helper(sets, set, nums, idx + 1);
      set.pop_back();
    }
  }
};
