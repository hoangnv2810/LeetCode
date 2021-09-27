package AugustChallenge2021;

import com.sun.source.tree.Tree;

import java.time.temporal.Temporal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeMap;

public class MaximumProfitInJobScheduling {
    public static int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i = 0; i < n; i++){
            jobs[i] = new int[] {startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, Comparator.comparingInt(a->a[1]));
        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0, 0);
        for(int[] job: jobs){
            int cur = dp.floorEntry(job[0]).getValue() + job[2];
            if(cur > dp.lastEntry().getValue()){
                dp.put(job[1], cur);
            }
        }
        return dp.lastEntry().getValue();
//        int[] dp = new int[n+1];
//        dp[0] = jobs[0][2];
//        for(int i = 1; i < n; i++){
//            for(int j = 0; j < i; j++){
//                if(jobs[i][0] >= jobs[j][1]){
//                    dp[i] = Math.max(dp[i], dp[j] + jobs[i][2]);
//                }
//                else {
//                    dp[i] = Math.max(jobs[i][2], dp[i]);
//                }
//            }
//        }
//        return Arrays.stream(dp).max().getAsInt();

    }

    public static void main(String[] args) {
        int[] startTime = {1,2,4,6,3};
        int[] endTime = {3,5,6,7,10};
        int[] profit = {20,20,70,60,100};
        int res = jobScheduling(startTime, endTime, profit);
        System.out.println(res);
    }
}
