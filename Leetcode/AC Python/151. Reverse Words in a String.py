class Solution:
    def reverseWords(self, s):
        return " ".join(s.strip().split()[::-1])