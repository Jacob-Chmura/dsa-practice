class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int num_unique = 1;
            for(int i = 1; i < nums.size(); ++i){
                if(nums[i] != nums[num_unique-1]){
                    nums[num_unique++] = curr_num;
                }
            }
            return num_unique;
        }
};
