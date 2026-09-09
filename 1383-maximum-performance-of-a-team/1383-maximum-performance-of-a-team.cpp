class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, 
                       vector<int>& efficiency, int k) {
        
        const int MOD = 1e9 + 7;

        // Store {efficiency, speed}
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        // Sort efficiency in decreasing order
        sort(engineers.rbegin(), engineers.rend());

        // Min heap to keep speeds
        priority_queue<int, vector<int>, greater<int>> pq;

        long long speedSum = 0;
        long long maxPerformance = 0;

        for (auto &engineer : engineers) {

            int eff = engineer.first;
            int spd = engineer.second;

            // Add current engineer's speed
            pq.push(spd);
            speedSum += spd;

            // If more than k engineers, remove smallest speed
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }

            // Current efficiency is the minimum efficiency
            maxPerformance = max(
                maxPerformance,
                speedSum * eff
            );
        }

        return maxPerformance % MOD;
    }
};
