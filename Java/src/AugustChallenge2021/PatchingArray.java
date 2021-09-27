package AugustChallenge2021;

public class PatchingArray {
    public static int minPatches(int[] nums, int n) {
        int res = 0, i = 0;
        long miss = 1;
        while(miss <= n){
            if(i < nums.length && nums[i] <= miss){
                miss += nums[i];
                i++;
            }
            else {
                miss += miss;
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,31,33};
        int n = 2147483647;
        minPatches(nums, n);
    }
}
