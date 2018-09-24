class Solution:
    def toLowerCase(self, str): 
        return "".join(chr(ord(c) + 32) if "A" <= c <= "Z" else c for c in str)
# class Solution:
#     def toLowerCase(self, str): 
#         return str.lower()