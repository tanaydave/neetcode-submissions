class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, maxCap = INT_MIN, cap = 0;
        while(i < j)
        {
            cap = min(heights[i],heights[j]) * (j - i);
            maxCap = max(cap,maxCap);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxCap;
    }
};
