package DataStructureI;

public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int maxhere = nums[0], res = nums[0];
        for(int i = 1; i < nums.length; i++){
            maxhere = Math.max(maxhere + nums[i], nums[i]);
            res = Math.max(res, maxhere);
        }
        return res;
    }
    public static void main(String[] args) {

    }
}
