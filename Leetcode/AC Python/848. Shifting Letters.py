class Solution(object):
    def shiftingLetters(self, S, shifts):
        for i in range(len(shifts)-1)[::-1]:
            shifts[i] += shifts[i+1]
        return "".join(chr((ord(c)-97+s) % 26+97) for (c, s) in zip(S, shifts))
