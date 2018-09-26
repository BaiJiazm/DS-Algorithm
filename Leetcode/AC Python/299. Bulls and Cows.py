import operator

class Solution:
    def getHint(self, secret, guess):
        bulls=sum(map(operator.eq, secret, guess))
        both=sum( min(secret.count(x), guess.count(x)) for x in set(guess))
        return '%dA%dB' % (bulls, both-bulls)