// Given a binary tree, determine if it is height-balanced.


// Runtime: 1ms      Memory:44.25MB

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public int height(TreeNode root){
        if(root==null || (root.left==null && root.right==null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        int left=height(root.left);
        int right=height(root.right);
        if(root.left!=null) left++;
        if(root.right!=null) right++;
        return Math.abs(left - right) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }
}