class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0],count = 1;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == ans)
            {
                count++;
            }
            else{
                count--;
            }
            if(count<1)
            {
                ans = nums[i];
            }
        }
        return ans;
  


    }
};