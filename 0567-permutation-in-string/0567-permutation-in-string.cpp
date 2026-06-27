class Solution {
public:
    bool checkInclusion(string s1, string s2) {
            if (s1.size() > s2.size()) return false;

        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }

        int left = 0;
        int count = s1.size();

        for (int right = 0; right < s2.size(); right++) {
            char ch = s2[right];

            // expand window
            if (mp.count(ch)) {
                if (mp[ch] > 0) count--;
                mp[ch]--;
            }

            if (count == 0) return true;

            // shrink window
            if (right - left + 1 == s1.size()) {
                char leftChar = s2[left];

                if (mp.count(leftChar)) {
                    if (mp[leftChar] >= 0) count++;
                    mp[leftChar]++;
                }
                left++;
            }
        }

        return false;
    }
};