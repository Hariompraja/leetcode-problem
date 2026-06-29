class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            //  find middle
            int mid = left + (right - left) / 2;

            //  if found, return index
            if (nums[mid] == target) {
                return mid;
            }

            //  check which half is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted

                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;   // target is in left half
                } else {
                    left = mid + 1;    // target is in right half
                }
            } else {
                // Right half is sorted

                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;    // target is in right half
                } else {
                    right = mid - 1;   // target is in left half
                }
            }
        }

      
        return -1;
    }
};