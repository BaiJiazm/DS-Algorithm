# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def leftHeight(self, root):
        return 0 if not root else 1+self.leftHeight(root.left)
    
    def rightHeight(self, root):
        return 0 if not root else 1+self.rightHeight(root.right)

    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        lh=self.leftHeight(root.left)
        rh=self.rightHeight(root.right)
        if lh==rh :
            return 2**(lh+1)-1
        lrh=1+self.rightHeight(root.left.right)
        if lh==lrh:
            return 2**lh+self.countNodes(root.right)
        return 2**rh+self.countNodes(root.left)