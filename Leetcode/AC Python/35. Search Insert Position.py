class Solution:
    def searchInsert(self, nums, target):
        return sorted(nums + [target]).index(target)