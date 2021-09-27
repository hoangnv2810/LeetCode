package AugustChallenge2021;

public class ComplexNumberMultiplication {
    public static String complexNumberMultiply(String num1, String num2) {
        String[] str1 = num1.split("\\+|i");
        String[] str2 = num2.split("\\+|i");
        int a_real = Integer.parseInt(str1[0]);
        int a_img = Integer.parseInt(str1[1]);
        int b_real = Integer.parseInt(str2[0]);
        int b_img = Integer.parseInt(str2[1]);
        return (a_real * b_real - b_img * a_img) + "+" + (a_real * b_img + b_real * a_img) + "i";
    }

    public static void main(String[] args) {
        String num1 = "1+-1i";
        String num2 = "1+-1i";
        String res = complexNumberMultiply(num1, num2);
        System.out.println(res);
    }
}
