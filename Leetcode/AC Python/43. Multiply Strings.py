class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        ans = [0]*(len(num1)+len(num2))
        pos = len(ans)-1

        for n1 in reversed(num1):
            tpos=pos
            for n2 in reversed(num2):
                ans[tpos] += int(n1) * int(n2)
                ans[tpos-1]+=ans[tpos]//10
                ans[tpos]%=10
                tpos-=1
            pos-=1
        
        tpos=0
        while tpos<len(ans)-1 and ans[tpos]==0 :
            tpos+=1
        
        return ''.join(map(str, ans[tpos:]))


s=Solution()
print(s.multiply("2", "3"))