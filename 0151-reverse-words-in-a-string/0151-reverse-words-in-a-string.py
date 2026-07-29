class Solution(object):
    def reverseWords(self, s):
        words = s.split()
        reverse_sentence = " ".join(words[::-1])

        return reverse_sentence