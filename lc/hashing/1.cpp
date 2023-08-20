class Solution {
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> targets;
    for (int i = 0; i < nums.size(); ++i) {
      if (targets.count(nums[i])) {
        return {i, targets[i]};
      }
      targets[target - nums[i]] = i;
    }
    return {};
  }
};
