class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorderTraversal(root: TreeNode):
    def traverse(node):
        if not node:
            return []
        return [node.val] + traverse(node.left) + traverse(node.right)
    
    return traverse(root)