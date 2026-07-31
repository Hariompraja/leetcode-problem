class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        

  
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {

            int j = i;
            int len = 0;

            // Pick maximum words for this line
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line OR only one word
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }

                line += string(maxWidth - line.size(), ' ');
            }

            // Fully justify
            else {

                int totalSpaces = maxWidth - len;
                int even = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(even + (extra > 0), ' ');
                    if (extra > 0)
                        extra--;
                }

                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
