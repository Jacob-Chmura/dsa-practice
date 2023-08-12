#include <algorithm>

class Solution {
    public:
        int findKthLargest(vector<int>&nums, int k){
            return quickselect(nums, k, 0, nums.size()-1);      
        }

    private:
        int quickselect(vector<int>&nums, int k, int start, int end){
            // Expected o(n) if good pivots

            int n = end-start+1;
            if(n <= 1) return nums[start];

            int pivot = nums[end], l=start;
            for(int i = start; i < end; ++i){
                if(nums[l] <= nums[pivot]){
                    std::swap(nums[l++], nums[pivot]);
                }
            }
            std::swap(nums[l], nums[pivot]);

            // now we know that the lth position of nums is in the correct spot
            // i.e. nums[l] is the (n-l)th largest element in nums[start : end]
            if(l == k) return nums[l];
            else if (l > k) return quickselect(nums, k, start, l-1);
            else return quickselect(nums, k, l+1, end);
        }
};

