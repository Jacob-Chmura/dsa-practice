class Solution {
public:
  void sortColors(vector<int> &nums) {
    // bucket sort will work here
    int buckets[3] = {0};
    for (auto x : nums)
      ++buckets[x];

    int idx = 0;
    for (int i = 0; i < 3; ++i) {
      while (buckets[i]) {
        nums[idx++] = i;
        --buckets[i];
      }
    }
  }
};
