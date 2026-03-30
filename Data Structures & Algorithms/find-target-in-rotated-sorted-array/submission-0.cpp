class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int piv = 0;

        // Find pivot (smallest element index)
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        piv = st;

        // Search in left half
        int result = binarySearch(nums, target, 0, piv - 1);
        if (result != -1) return result;

        // Search in right half
        return binarySearch(nums, target, piv, nums.size() - 1);
    }
};
