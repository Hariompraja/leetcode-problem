class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        vector<int> pCount(26, 0), windowCount(26, 0);

        // Count characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int windowSize = p.size();

        for (int i = 0; i < s.size(); i++) {
            // add current character to window
            windowCount[s[i] - 'a']++;

            // remove character that goes out of window
            if (i >= windowSize) {
                windowCount[s[i - windowSize] - 'a']--;
            }

            // compare counts when window size matches p
            if (i >= windowSize - 1) {
                if (windowCount == pCount) {
                    ans.push_back(i - windowSize + 1);
                }
            }
        }

        return ans;
    }
};