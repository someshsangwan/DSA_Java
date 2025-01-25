package TREE;

// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    class Pair {
        public int height;
        public boolean bal;

        Pair(int height, boolean bal) {
            this.bal = bal;
            this.height = height;
        }
    }

    public Pair check(TreeNode root) {
        if (root == null) {
            return new Pair(0, true);
        }
        Pair left = check(root.left);
        Pair right = check(root.right);
        boolean leftb = left.bal;
        boolean rightb = right.bal;
        int leftheight = left.height;
        int rightheight = right.height;
        boolean diff = Math.abs(rightheight - leftheight) <= 1;
        if (leftb && rightb && diff) {
            Pair res = new Pair(Math.max(leftheight, rightheight) + 1, true);
            return res;

        } else {
            Pair res = new Pair(Math.max(leftheight, rightheight) + 1, false);
            return res;
        }
    }

    public boolean isBalanced(TreeNode root) {
        Pair res = check(root);
        return res.bal;

    }
}