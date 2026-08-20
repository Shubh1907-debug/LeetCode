class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // Step 2: Traverse and merge
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = merged.back();

            if (intervals[i][0] <= last[1]) {
                // Overlap → merge
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap → add new interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }

};