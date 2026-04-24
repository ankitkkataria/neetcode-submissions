# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    dia = 0

    def f(self, root):
        if(not root):
            return 0
        leftHeight = self.f(root.left)
        rightHeight = self.f(root.right)
        self.dia = max(self.dia, leftHeight + rightHeight + 1)        
        return 1 + max(leftHeight, rightHeight)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.f(root)
        return self.dia - 1


        