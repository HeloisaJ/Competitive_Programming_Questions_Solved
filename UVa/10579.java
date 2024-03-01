import java.math.BigInteger;
import java.util.Scanner;

class Main {

    public static void main(String[] args){ // Fibonacci Numbers
        Scanner in = new Scanner(System.in);
        int maximo, num;
        BigInteger [] lista = new BigInteger[5123];
        lista[0] = BigInteger.ONE;
        lista[1] = BigInteger.ONE;
        maximo = 2;
        while(in.hasNext()){
            num = in.nextInt();
            if(maximo <= num){
                for(int i = maximo; i <= num; i++){
                    lista[i] = lista[i - 1].add(lista[i - 2]);
                }
                maximo = num + 1;
            }
            System.out.println(lista[num - 1]);
        }
        in.close();
    }
}
