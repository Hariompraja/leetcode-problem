class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (auto x : nums) {
            freq[x]++;
        }

        for (auto &p : freq) {
            if (p.second > nums.size() / 2) {
                return p.first;
            }
        }

        return -1;
    }
};