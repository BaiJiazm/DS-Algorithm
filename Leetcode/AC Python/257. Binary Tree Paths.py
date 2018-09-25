class Solution:
    def binaryTreePaths(self, root):
        if not root:
            return []
        return [str(root.val)+'->'+path 
                for kid in (root.left, root.right) if kid
                for path in self.binaryTreePaths(kid)] or [str(root.val)]