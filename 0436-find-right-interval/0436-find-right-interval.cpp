class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts; // {start, original_index}
        
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        
        sort(starts.begin(), starts.end()); // sort by start
        
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            
            // Binary search for smallest start >= end
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (starts[mid].first >= end) {
                    ans = starts[mid].second;
                    r = mid - 1; // try to find smaller start
                } else {
                    l = mid + 1;
                }
            }
            
            result[i] = ans;
        }
        
        return result;
    }
};