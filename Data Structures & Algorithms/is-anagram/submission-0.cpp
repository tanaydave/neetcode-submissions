class Solution {
public:
    bool isAnagram(string s, string t) {
        
         if (s.length() != t.length()) {
            return false;
        }
        vector<int>ans(26,0);
        for(char c : s)
        {
            ans[c - 'a']++;
        }
        for(char d : t)
        {
            ans[d - 'a']--;
        }
        
        for (int i=0;i<ans.size();i++)
        {
            if(ans[i] != 0)
            {
                return false;
            }
        }
        return true;


    }
    }
;
