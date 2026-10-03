class Solution:
    temp = None

    def flatten(self, root):
        self.helper(root)

    def helper(self, root):
        if root is None:
            return

        left = root.left
        right = root.right

        if self.temp is not None:
            self.temp.right = root

        root.left = None
        self.temp = root

        self.helper(left)
        self.helper(right)