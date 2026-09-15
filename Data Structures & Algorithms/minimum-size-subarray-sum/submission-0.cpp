class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, n = nums.size(),minLen = INT_MAX, sum = 0;
        for(int i = 0 ; i < n; i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                minLen = min(minLen, i - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};