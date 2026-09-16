class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() || t == "") return "";

        int left = 0, resLen = INT_MAX, res = -1, target = 0, current = 0;
        int sMap[128] = { 0 };
        int tMap[128] = { 0 };
        for(char c : t) tMap[c]++;

        for(int val : tMap)
            if(val > 0) target++;

        for(int right = 0; right < s.size(); right++) {   
            sMap[s[right]]++;
            if(tMap[s[right]] != 0 && sMap[s[right]] == tMap[s[right]]) current++;

            while(current == target) {
                if(right - left + 1 < resLen) {
                    res = left;
                    resLen = right - left + 1;
                }
                sMap[s[left]]--;
                if(tMap[s[left]] != 0 && tMap[s[left]] > sMap[s[left]]) current--;
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res, resLen);
    }
};