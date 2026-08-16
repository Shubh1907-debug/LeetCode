class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        
        vector<vector<char>> buckets(s.size() + 1);
        for (auto& [ch, count] : freq) {
            buckets[count].push_back(ch);
        }
        
        string result;
        result.reserve(s.size());
        for (int freq = s.size(); freq >= 1; freq--) {
            for (char ch : buckets[freq]) {
                result.append(freq, ch);
            }
        }
        
        return result;
    }
};