import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args) { // Fibonacci Freeze
        Scanner input = new Scanner(System.in);
        BigInteger [] fib = new BigInteger[5123];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        int pos = 0, n = 1;
        while(pos != -1){
            try {
                pos = input.nextInt();
            } catch (Exception e) {
                break;
            }
            while(pos > n){
                fib[n + 1] = fib[n].add(fib[n - 1]);
                n++;
            }
            System.out.println("The Fibonacci number for " + pos + " is " +  fib[pos]);
        }
        input.close();
    }
}