class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;
        int el1 = 0 , count1 = 0, el2 = 0 , count2 = 0;
        for(int num : nums)
        {
            if(count1 == 0 && num != el2)
            {
                count1 = 1;
                el1 = num;
            }
            else if(count2 == 0 && num != el1)
            {
                count2 = 1;
                el2 = num;
            }
            else if(num == el1) count1++;
            else if(num == el2) count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        //mnaully checking whether the elements are occurring more than n/3 times or not
        count1 = 0, count2 = 0;
        for(int i = 0 ;i < nums.size() ; i++)
        {
            if(nums[i] == el1) count1++;
            if(nums[i] == el2) count2++;

        }
        if(count1 > nums.size()/3) result.push_back(el1);
        if(count2 > nums.size()/3) result.push_back(el2);

        return result;        
    }
};