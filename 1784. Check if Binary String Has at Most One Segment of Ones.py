# 1784. Check if Binary String Has at Most One Segment of Ones
# Dificulty easy
# https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/


class Solution(object):
    def checkOnesSegment(self, s):
        """
        :type s: str
        :rtype: bool
        """
   
        if '01' in s:
            return False
    
        return True
           