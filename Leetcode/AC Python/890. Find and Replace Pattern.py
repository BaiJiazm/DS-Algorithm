class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def fun(w):
            d = {}
            for c in w:
                d[c] = d.get(c, len(d))
            return "".join(chr(d[c]+97) for c in w)
        return [w for w in words if fun(w) == fun(pattern)]
