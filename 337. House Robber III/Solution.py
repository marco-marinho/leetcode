class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.dfs(root))

    def dfs(self, node: Optional[TreeNode]) -> Tuple[int, int]:
        if node is None:
            return 0, 0
        left = self.dfs(node.left)
        right = self.dfs(node.right)
        return left[1] + right[1] + node.val, max(right) + max(left)
