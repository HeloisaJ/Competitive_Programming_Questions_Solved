import java.util.Scanner;
import java.math.BigInteger;

class Main{

    public static BigInteger ajuste(BigInteger n){
        while(n.mod(BigInteger.TEN) == BigInteger.ZERO){
            n = n.divide(BigInteger.TEN);
        }
        return n;
    }

    public static void main(String[] args) { // Adding Reversed Numbers
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        for(int i = 0; i < n; i++){
            BigInteger n1, n2;
            n1 = in.nextBigInteger();
            n2 = in.nextBigInteger();
            String s1 = "", s2 = "";
            n1 = ajuste(n1);
            n2 = ajuste(n2);
            s1 = n1.toString();
            s2 = n2.toString();
            s1 = new StringBuilder(s1).reverse().toString();
            s2 = new StringBuilder(s2).reverse().toString();
            n1 = new BigInteger(s1);
            n2 = new BigInteger(s2);
            BigInteger sum = n1.add(n2);
            sum = ajuste(sum);
            String res = sum.toString();
            res = new StringBuilder(res).reverse().toString();
            System.out.println(res);
        }
        in.close();
    }
}