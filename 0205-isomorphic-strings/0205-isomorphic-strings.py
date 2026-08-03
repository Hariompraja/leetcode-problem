class Solution(object):
    def isIsomorphic(self, s, t):
    
        if len(s) != len(t):
            return False

        last_s = [0] * 256
        last_t = [0] * 256

        for i in range(len(s)):
            if last_s[ord(s[i])] != last_t[ord(t[i])]:
                return False

            last_s[ord(s[i])] = i + 1
            last_t[ord(t[i])] = i + 1

        return True
        