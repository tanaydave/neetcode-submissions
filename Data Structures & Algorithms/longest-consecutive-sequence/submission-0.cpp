class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int max_len = INT_MIN, length = 0;
        if(!nums.size()) return length;
        for(int el : s)
        {
            if(s.find(el - 1) == s.end())
            {
                length = 1;
                while(s.find(el + 1) != s.end())
                {
                    length++;
                    el +=1;
                }
                max_len = max(length,max_len);
            }
        }
        return max_len;
        
    }
};
