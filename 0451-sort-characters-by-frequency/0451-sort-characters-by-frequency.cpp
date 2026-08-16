class Solution {
public:
    string frequencySort(string s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Move to vector of pairs for sorting
        vector<pair<char, int>> chars(freq.begin(), freq.end());
        
        // Sort by frequency in descending order
        sort(chars.begin(), chars.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
            return a.second > b.second;
        });
        
        // Build result string
        string result;
        result.reserve(s.size());
        for (auto& [ch, count] : chars) {
            result.append(count, ch);
        }
        
        return result;
    }
};