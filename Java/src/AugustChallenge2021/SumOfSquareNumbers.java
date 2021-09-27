package AugustChallenge2021;

import java.util.Scanner;

public class SumOfSquareNumbers {
    // Approach: Sqrt
//    static boolean judgeSquareSum(int c) {
//        for(int i = 1; i <= Math.sqrt(c); i++){
//            double temp = Math.sqrt(c-i*i);
//            if(temp == (int)temp) return true;
//        }
//        return false;
//    }

    // Approadch: Binary Search
    static boolean judgeSquareSum(int c){
       for(int i = 1; i <= Math.sqrt(c); i++){
           int temp = c-i*i;
           if(binary_search(0, temp, temp)){
               return true;
           }
       }
       return false;
    }

    public static boolean binary_search(int l, int r, int target){
        if(l > r) return false;
        int mid = l + (r-l)/2;
        if(mid*mid  == target) return true;
        if(mid*mid > target) return binary_search(l, mid-1, target);
        return binary_search(mid+1, r, target);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
            int n = sc.nextInt();
            if(judgeSquareSum(n)) System.out.println("Yes");
            else System.out.println("No");
            t--;
        }
    }
}
