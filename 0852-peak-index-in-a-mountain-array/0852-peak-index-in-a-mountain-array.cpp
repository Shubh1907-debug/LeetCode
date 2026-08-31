class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;      // Peak is to the right
            } else {
                right = mid;         // Peak is at mid or to the left
            }
        }

        return left;
    }
};