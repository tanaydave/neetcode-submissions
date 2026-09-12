class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        unordered_map<char,int> mpp;   

        for(int end = 0; end < s.size(); end++) {
            
            if(mpp.count(s[end]) && mpp[s[end]] >= start) {
                start = mpp[s[end]] + 1;   
            }
            mpp[s[end]] = end;             
            maxLen = max(maxLen, end - start + 1);   
        }
        return maxLen;
    }
};