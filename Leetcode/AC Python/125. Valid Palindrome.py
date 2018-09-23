class Solution:
    def isPalindrome(self, s):
        l, r = 0, len(s)-1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True

import string

class Solution1:
    def isPalindrome(self, s):
        # Better:
        translates = str.maketrans("", "", string.punctuation + " ")
        s = s.translate(translates).lower()

        return s == s[::-1]
