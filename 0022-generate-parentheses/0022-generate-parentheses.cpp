class Solution {
public:
    vector<string> ans;

    void backTrack(string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            backTrack(current + "(", open + 1, close, n);
        }

        if (close < open) {
            backTrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backTrack("", 0, 0, n);
        return ans;
    }
};