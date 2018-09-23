class Solution:
    def customSortString(self, S, T):
            """
            :type S: str
            :type T: str
            :rtype: str
            """
            l = []
            for i in S:
                    l.append(i*T.count(i))
            for i in T:
                if i not in S:
                    l.append(i)
            return ''.join(l)
        