import operator

class Solution:
    def singleNumber(self, nums):
        dict={}
        for num in nums:
            dict[num]=dict.get(num, 0)+1
        for key, val in dict.items():
            if val==1:
                return key

    def singleNumber1(self, nums):
        return reduce(operator.xor, nums)