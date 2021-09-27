package AugustChallenge2021;

import java.util.*;

public class TwoSumIVInputIsABST {
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){};
        TreeNode(int val){
            this.val = val;
        }
    }
    public class Solution {
        public boolean findTarget(TreeNode root, int k) {
            Set<Integer> set = new HashSet<>();
            Queue<TreeNode> q = new LinkedList<>();
            q.add(root);
            while(!q.isEmpty()){
                if(q.peek() != null){
                    TreeNode node = q.remove();
                    if(set.contains(k-node.val)) return true;
                    set.add(node.val);
                    q.add(node.left);
                    q.add(node.right);
                } else {
                    q.remove();
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {

    }
}
