package DataStructureI;

public class MergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int t = m+n-1;
        while(m-1 >= 0 && n-1>= 0){
            if(nums1[m-1] > nums2[n-1]){
                nums1[t--] = nums1[m-1];
                m--;
            } else {
                nums1[t--] = nums2[n-1];
                n--;
            }
        }
        while(n-1 > 0){
            nums1[t--] = nums2[n--];
        }
    }
    public static void main(String[] args) {

    }
}
