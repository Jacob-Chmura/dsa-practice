#include <algorithm>

class Solution {
    public:
        vector<int> insertionSort(vector<int>& nums){
            for(int i = 1; i < nums.size(); ++i){
                 int j = i - 1;
                 while(j >= 0 && nums[j] > nums[j+1]){
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                    --j;
                 }
            }
            return nums;
        }
        vector<int> heapSort(vector<int>& nums){
            int n = nums.size();
            buildMaxHeap(nums, n);
            for(int i = n-1; i >= 0; --i){
                std::swap(nums[0], nums[i]);
                heapify(nums, 0, i);
            }
            return nums;
        }

    private:
        void buildMaxHeap(vector<int>& nums, int n){
            for(int i = n/2 - 1; i >= 0; --i) heapify(nums, i, n);
        }

        void heapify(vector<int>& nums, int i, int n){
            int largest = i, l = left_child(i), r = right_child(i);
            if(l < n && nums[l] > nums[largest]) largest = l;
            if(r < n && nums[r] > nums[largest]) largest = r;

            if(largest != i){
                std::swap(nums[i], nums[largest]);
                heapify(nums, largest, n);
            }
        }

        int left_child(int i){
            return 2 * i + 1;
        }
        int right_child(int i){
            return 2 * i + 2;
        }
};

