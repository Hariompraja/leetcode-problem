class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;

        // First window sum
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }

        double maxAvg = currSum / k;

        // Sliding window
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i];        // add new element
            currSum -= nums[i - k];    // remove old element

            double currAvg = currSum / k;
            maxAvg = max(maxAvg, currAvg);
        }

        return maxAvg;
    }
};