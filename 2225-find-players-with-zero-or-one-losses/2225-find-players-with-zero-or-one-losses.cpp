class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossCount;
        
       
        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
            lossCount[loser]++;
        }
        
        vector<int> noLosses, oneLoss;
        for (auto& [player, losses] : lossCount) {
            if (losses == 0) {
                noLosses.push_back(player);
            } else if (losses == 1) {
                oneLoss.push_back(player);
            }
        }
        
        sort(noLosses.begin(), noLosses.end());
        sort(oneLoss.begin(), oneLoss.end());
        
        return {noLosses, oneLoss};
    }
};