from collections import defaultdict

class Solution:
    def isIsomorphic(self, s, t):
        d1, d2=defaultdict(int), defaultdict(int)
        for i in range(len(s)):
            if d1[ord(s[i])]!=d2[ord(t[i])]:
                return False
            d1[ord(s[i])]=d2[ord(t[i])]=i+1
        return True