class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j = people.size() - 1;
        int count = 0;
        while(j >=0 && people[j] == limit)
        {
            count++;
            j--;
        } 
        while(i < j)
        {
            if(people[i] + people[j] <= limit)
            {
                count++;
                i++;
                j--;
            } 
            else
            {
                count++;
                j--;
            }

        }
        if(i == j) count++;
        return count;
    }
};