package DataStructureI;

import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(mp.containsKey(target-nums[i])){
                res[1] = i;
                res[0] = mp.get(target-nums[i]);
                return res;
            }
            mp.put(nums[i], i);
        }
        return res;

    }
    public static void main(String[] args) {

    }
}
