package AugustChallenge2021;

public class LongestUncommonSubsequenceII {
    public int findLUSlength(String[] strs) {
        int res = -1, n = strs.length;
        for(int i = 0; i < n; i++){
            if(strs[i].length() < res) continue;
            int j = 0;
            while(j < n){
                if(i != j && isSubsequence(strs[i], strs[j])) break;
                j++;

            }
            if(j == n) res = Math.max(res, strs[i].length());
        }
        return res;
    }
    public boolean isSubsequence(String a, String b){
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()){
            if(a.charAt(i) == b.charAt(j++)) i++;
        }
        return i == a.length();
    }

    public static void main(String[] args) {

    }
}
