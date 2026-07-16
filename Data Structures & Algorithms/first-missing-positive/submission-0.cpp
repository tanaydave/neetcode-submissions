class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int correct;
        int i = 0;
        while(i < nums.size())
        {   
            correct = nums[i] - 1;
            if(nums[i]>0 && nums[i] <=nums.size() && nums[correct] != nums[i])
            {
                swap(nums[i],nums[correct]);
            }
            else i++;
        }
        for(int i = 0;i < nums.size(); i++)
        {
            if(nums[i] != i + 1)
            {
                return i+1;
            }   
        }
        return nums.size()+1;
      
    }
};