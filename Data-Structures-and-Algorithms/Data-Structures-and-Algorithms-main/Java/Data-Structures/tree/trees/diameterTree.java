// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.


// Runtime: 9ms      Memory:44.34MB


package trees;

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


    public int diameterOfBinaryTree(TreeNode root) { 

        if(root==null) return 0;   

        int left=diameterOfBinaryTree(root.left);
        int right=diameterOfBinaryTree(root.right);

        int center=height(root.left) + height(root.right);
        if(root.left!=null) center++;
        if(root.right!=null) center++;

        int max=Math.max(left,Math.max(center,right));
        return max;
    }  
}
