class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int n1= s1.size(), n2 = s2.size(), matches = 0;
        if(n1 > n2) return false;
        for (int i = 0; i < n1; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq1[i] == freq2[i]) matches++;
        }
        int left = 0, right = n1;
        while(right < n2)
        {
            if(matches == 26) return true;
            
            int key = s2[right] - 'a';
            freq2[key]++;
            if(freq1[key] == freq2[key]) matches++;
            else if (freq1[key] + 1 == freq2[key]) matches--;

            key = s2[left] - 'a';
            freq2[key]--;
            if(freq1[key] == freq2[key]) matches++;
            else if (freq1[key]  == freq2[key] + 1) matches--;

            left++;
            right++;
        }

        return matches == 26 ? true : false;
    }
};
