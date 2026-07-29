#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

        // Count characters in magazine
        for (char c : magazine) {
            count[c - 'a']++;
        }

        // Use characters for ransomNote
        for (char c : ransomNote) {
            count[c - 'a']--;

            
            if (count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

