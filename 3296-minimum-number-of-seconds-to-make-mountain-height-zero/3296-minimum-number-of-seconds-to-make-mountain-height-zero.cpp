class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long totalTime = 0;
        for (int t : workerTimes) {
            totalTime += t;
        }

        long long v = (long long)ceil((double)mountainHeight / n);

        long long start = 1;
        long long end = v * (v + 1) * *max_element(workerTimes.begin(), workerTimes.end()) / 2;

        while (start < end) {
            long long mid = (start + end) / 2;
            long long totalWork = 0;
            for (int t : workerTimes) {
                totalWork += (long long)floor(sqrt(2 * mid / (double)t + 0.25) - 0.5);
            }

            if (totalWork >= mountainHeight) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};