// Given the root of a binary tree, return the inorder traversal of its nodes' values.


// Runtime: 0ms      Memory:41.30MB


package trees;

import java.util.ArrayList;
import java.util.List;

public class inorderTraversl {
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
    static void traverse(TreeNode root,List<Integer> ino ){
        if(root==null)  return;
        traverse(root.left,ino);
        ino.add(root.val);
        traverse(root.right,ino);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ino=new ArrayList<>();
        traverse(root,ino);
        return ino;
    }
}
