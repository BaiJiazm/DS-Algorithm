import collections

class Solution:
    def findRepeatedDnaSequences(self, s):
        dict=collections.defaultdict(int)
        for i in range(len(s)):
            dict[s[i:i+10]]+=1
        return [key for key, value in dict.items() if value>1]