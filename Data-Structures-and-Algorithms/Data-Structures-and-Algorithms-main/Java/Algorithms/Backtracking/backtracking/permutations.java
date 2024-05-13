// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


// Runtime: 1ms      Memory:44.04MB


package backtracking;

import java.util.ArrayList;
import java.util.List;


class Solution {

    static void helper(int[] nums,List<Integer> ds,int[] isValid,List<List<Integer>> ans){
        if(ds.size()==nums.length){
            List<Integer> n=new ArrayList<>();
            for(int i=0;i<nums.length;i++)
                n.add(ds.get(i));
            ans.add(n);
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(isValid[i]==0){
                 ds.add(nums[i]);
                isValid[i]=1;
                helper(nums,ds,isValid,ans);
                isValid[i]=0;
                ds.remove(ds.size()-1);
            }  
        }
            
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans= new ArrayList<>();
        List<Integer> ds=new ArrayList<>();
        int[] isValid=new int[nums.length];
        helper(nums,ds,isValid,ans);
        return ans;
    }
}