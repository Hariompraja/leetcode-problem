// 20. Valid Parentheses
// Dificulty easy

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false;

                if ((st.top() == '(' && ch == ')') ||
                    (st.top() == '{' && ch == '}') ||
                    (st.top() == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
