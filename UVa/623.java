import java.math.BigInteger;
import java.util.Scanner;

class Main{

    public static BigInteger [] dp;
    public static int cont;

    public static void main(String[] args) { // 500!
        Scanner in = new Scanner(System.in);
        dp = new BigInteger[1234];
        cont = 1;
        dp[0] = BigInteger.ONE;
        dp[1] = BigInteger.ONE;
        int n;
        while(in.hasNext()){
            n = in.nextInt();
            while(cont < n){
                cont++;
                dp[cont] = dp[cont - 1].multiply(BigInteger.valueOf(cont));
            }
            System.out.println(n + "!");
            System.out.println(dp[n]);
        }
        in.close();
    }

}