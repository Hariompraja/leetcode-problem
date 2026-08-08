static int last[300001];
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n = word1.size(), m = word2.size();
        fill(last , last + m , -1);
        for(int i = n - 1, j = m - 1; i >= 0; --i){
            if(j >= 0 && word1[i] == word2[j]) last[j--] = i;
        }
        bool skip = false;
        vector<int> res;
        res.reserve(m);
        for(int i = 0, j = 0; i < n && j < m; ++i){
            if(word1[i] == word2[j] || (!skip && (j == m - 1 || i < last[j + 1]))){
                if(word1[i] != word2[j++]) skip = true;
                res.push_back(i);
            }
        }
        return res.size() == m ? res : vector<int>();
    }
};