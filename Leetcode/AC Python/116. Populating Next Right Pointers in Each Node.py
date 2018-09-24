# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root: return
        while root.left:
            cur = root.left
            prev = None
            while root:
                if prev: prev.next = root.left
                root.left.next = root.right
                prev = root.right
                root = root.next
            root = cur