class Solution(object):
    def strStr(self, haystack, needle):
        
        if not needle:
            return 0

        m = len(needle)
        lps = [0] * m

        j = 0
        for i in range(1, m):
            while j and needle[i] != needle[j]:
                j = lps[j - 1]
            if needle[i] == needle[j]:
                j += 1
                lps[i] = j

        j = 0
        for i in range(len(haystack)):
            while j and haystack[i] != needle[j]:
                j = lps[j - 1]
            if haystack[i] == needle[j]:
                j += 1
                if j == m:
                    return i - m + 1

        return -1