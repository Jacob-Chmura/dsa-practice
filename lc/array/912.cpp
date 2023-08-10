class Solution {

    public:
        vector<int> sortArray(vector<int>& nums){
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
};

