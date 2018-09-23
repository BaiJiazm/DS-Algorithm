class Solution:
    def validPalindrome(self, s):
            i = 0
            while i < len(s) / 2 and s[i] == s[-(i + 1)]: i += 1
            s = s[i:len(s) - i]
            return s[1:] == s[1:][::-1] or s[:-1] == s[:-1][::-1]
