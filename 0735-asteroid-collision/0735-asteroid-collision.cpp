class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                
                if (abs(st.top()) < abs(asteroid)) {
                  
                    st.pop();
                }
                else if (abs(st.top()) == abs(asteroid)) {
                    // Both explode
                    st.pop();
                    asteroid = 0;
                    break;
                }
                else {
                    
                    asteroid = 0;
                    break;
                }
            }

         
            if (asteroid != 0) {
                st.push(asteroid);
            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};