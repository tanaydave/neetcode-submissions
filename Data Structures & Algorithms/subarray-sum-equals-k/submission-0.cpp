class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;       // empty prefix, before array starts

        int count = 0;
        int prefSum = 0;

        for (int j = 0; j < nums.size(); j++) {
            prefSum += nums[j];          // build prefix sum on the fly

            int val = prefSum - k;       // what prefix sum do we need to have seen?

            if (mp.find(val) != mp.end())
                count += mp[val];        // found it, add all occurrences

            mp[prefSum]++;               // record current prefix sum
        }

        return count;
    }
};