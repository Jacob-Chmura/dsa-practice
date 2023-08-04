class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int num_unchanged = 0, i = 0;
        while(i < nums.size()){
            if(nums[i] != val){
                nums[num_unchanged++] = nums[i];
            }
            i++;
        }
        return num_unchanged;
    }
};
