package DataStructureI;

import java.util.Arrays;

public class ContainsDuplicate {
    public static boolean containsDuplicate(int[] nums) {
        int tmp = nums[0];
        Arrays.sort(nums);
        for(int i = 1; i < nums.length; i++){
            if(tmp == nums[i]){
                return true;
            } else {
                tmp = nums[i];
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int[] nums = {1, 3};
        containsDuplicate(nums);
    }
}
