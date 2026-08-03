class Solution(object):
    def isSubsequence(self, s, t):
     
        j = 0
        for c in t:
            if j < len(s) and c == s[j]:
                j += 1
        return j == len(s)
        