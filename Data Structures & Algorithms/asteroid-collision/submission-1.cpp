class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> state;
        for(int num : asteroids)
        {
            if(num > 0)
            {
                state.push_back(num);
            }
            else
            {
                while(!state.empty() && state.back() > 0 && state.back() < abs(num))
                {
                    state.pop_back();
                }
                if( !state.empty() && state.back() == abs(num))
                {
                    state.pop_back();
                }
                else if(state.empty() || state.back() < 0)
                {
                    state.push_back(num);
                }

            }
            
        }
        return state;
        
    }
};