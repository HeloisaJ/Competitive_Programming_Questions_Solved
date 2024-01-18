import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static BigInteger [] dp;
    public static void main(String[] args) { // Just the Facts
        dp = new BigInteger[112345];
        int ref = 1;
        dp[0] = BigInteger.ONE;
        dp[1] = BigInteger.ONE;
        Scanner in = new Scanner(System.in);
        int n;
        while(in.hasNext()){
            n = in.nextInt();
            if(ref < n){
                for(int i = ref; i <= n; i++){
                    dp[i] = dp[i - 1].multiply(BigInteger.valueOf(i));
                }
                ref = n;
            }
            BigInteger res = dp[n];
            while(res.mod(BigInteger.TEN) == BigInteger.ZERO){
                res = res.divide(BigInteger.TEN);
            }
            res = res.mod(BigInteger.TEN);
            if(n < 10){
                System.out.print("    " + n);
            }
            else if(n < 100){
                System.out.print("   " + n);
            }
            else if(n < 1000){
                System.out.print("  " + n);
            }
            else if(n < 10000){
                System.out.print(" " + n);
            }
            else{
                System.out.print(n);
            }
            System.out.println(" -> " + res);
        }
        in.close();
    }
}