import itertools

class Solution:
    def ambiguousCoordinates(self, S):
        S = S[1:-1]

        def f(S):
            if not S or len(S) > 1 and S[0] == S[-1] == '0':
                return []
            if S[-1] == '0':
                return [S]
            if S[0] == '0':
                return [S[0]+'.'+S[1:]]
            return [S]+[S[:i]+'.'+S[i:] for i in range(1, len(S))]
        return ['(%s, %s)' % (a, b) for i in range(len(S)) for a, b in itertools.product(f(S[:i]), f(S[i:]))]

s = Solution()
for a in s.ambiguousCoordinates("123") :
    print (a)
