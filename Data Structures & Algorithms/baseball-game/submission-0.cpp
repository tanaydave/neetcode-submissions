class Solution {
public:
    int calPoints(vector<string>& operations) {
        int score = 0,size = 0;
        vector<int>nums;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "+")
            {
                nums.push_back(nums[size - 1] + nums[size - 2]);
                size++;
            }

            else if(operations[i] == "D")
            {
                nums.push_back(nums[size - 1] * 2);
                size++;
            }

            else if(operations[i] == "C")
            {
                nums.pop_back();
                size--;
            }

            else
            {
                nums.push_back(stoi(operations[i]));
                size++;
            }

        }
        for(int num : nums)
        {
            score += num;
        }
        return score;
    }
};