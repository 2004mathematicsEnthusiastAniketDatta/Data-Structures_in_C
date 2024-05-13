// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.


// Runtime: 8ms      Memory:42.02MB

package trees;
import java.util.ArrayList;

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
    public void path(TreeNode root,List<String> p,String s){
        if(root==null)
            return;
        if(root.left==null && root.right==null){
            p.add(s+=root.val);
        }        
        path(root.left,p,s+root.val+"->");
        path(root.right,p,s+root.val+"->");
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> p= new ArrayList<>();
        path(root,p,"");
        return p;
    }
}