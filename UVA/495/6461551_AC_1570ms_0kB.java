import java.util.Scanner;
import java.math.BigInteger;
 
public class Main {
 
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            BigInteger a, b,c;
            a = BigInteger.ZERO;
            b = BigInteger.ONE;
            c=BigInteger.ZERO;
            long num;
            num = sc.nextInt();
 
            for (int i = 1; i < num; i++) {
                c=a.add(b);
                a=b;
                b=c;
            }
            if(num==1)c=BigInteger.valueOf(1);
            System.out.println("The Fibonacci number for "+num+" is "+c);
        }
    }
}