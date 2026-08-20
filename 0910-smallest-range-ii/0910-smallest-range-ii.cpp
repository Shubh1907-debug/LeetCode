class Solution {
public:
  
      int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[n-1] - nums[0];   // initial difference
        int smallest = nums[0] + k;
        int largest = nums[n-1] - k;

        for (int i = 0; i < n - 1; i++) {
            int min_val = min(smallest, nums[i+1] - k);
            int max_val = max(largest, nums[i] + k);
            ans = min(ans, max_val - min_val);
        }

        return ans;
    }
};