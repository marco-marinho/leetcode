# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def generate(self, lower: int, upper: int) -> Optional[TreeNode]:
        if lower > upper:
            yield None

        for root in range(lower, upper + 1):
            for left in self.generate(lower, root - 1):
                for right in self.generate(root + 1, upper):
                    yield TreeNode(root, left, right)

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return list(self.generate(1, n))
