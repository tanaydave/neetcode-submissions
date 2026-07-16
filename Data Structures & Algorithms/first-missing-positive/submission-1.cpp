class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        // assigning each element to its correct position within the array
        //dont use for loop because you will have to check the swapped number as well 
        //if you use for, the swapped number wont be checked as 'i' increments
        while(i < nums.size()) {   
            // range check FIRST before computing correct to avoid INT_MIN overflow
            if(nums[i] > 0 && nums[i] <= nums.size()) {
                int correct = nums[i] - 1;    // only computed when safe
                if(nums[correct] != nums[i])
                    swap(nums[i], nums[correct]);
                else 
                    i++;
            }
            else i++;
        }

        //checking for first number which is not at its correct position
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }   
        }
        return nums.size() + 1;
    }
};