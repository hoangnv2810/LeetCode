package DataStructureI;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class IntersectionOfTwoArraysII {
    public int[] intersect(int[] nums1, int[] nums2) {
        int i = 0, j = 0;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        ArrayList<Integer> res = new ArrayList<>();
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] == nums2[j]){
                res.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]){
                j++;
            } else {
                j++;
            }
        }
        int[] ans = new int[res.size()];
        for(int l = 0; l < res.size(); l++){
            ans[l] = res.get(l);
        }
        return ans;
    }
    public static void main(String[] args) {

    }
}
