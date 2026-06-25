class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        // Mark coverage of existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int v = lights[i];
                int l = max(0, i - v);
                int r = min(n - 1, i + v);

                diff[l]++;
                diff[r + 1]--;
            }
        }

        vector<int> visible(n, 0);
        int cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            visible[i] = (cur > 0);
        }

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (visible[i]) {
                i++;
                continue;
            }

            int len = 0;
            while (i < n && !visible[i]) {
                len++;
                i++;
            }

            ans += (len + 2) / 3;   // ceil(len/3)
        }

        return ans;
    }
};