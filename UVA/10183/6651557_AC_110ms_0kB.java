import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc  = new Scanner(System.in);
        
        BigInteger fib[] = new BigInteger [510];
        fib[1] = BigInteger.ONE;
        fib[0] = BigInteger.ZERO;
        //System.out.println(fib[0].add(fib[1]));
        for(int i = 2 ; i<=500;i++){
            fib[i]=BigInteger.ZERO;
            fib[i] = fib[i].add(fib[i-1]);  
            fib[i] = fib[i].add(fib[i-2]);
            //System.out.println(fib[i]);
        }
        BigInteger a , b;
        
        while(sc.hasNext()){
            
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            int counter = 0;
            if(a.compareTo(BigInteger.ZERO)==0&&b.compareTo(BigInteger.ZERO)==0)break;
            else if(a.compareTo(BigInteger.ZERO)==0&&b.compareTo(BigInteger.ONE)==0)System.out.println(1);
            else if(a.compareTo(BigInteger.ONE)==0&&b.compareTo(BigInteger.ONE)==0)System.out.println(1);
            else{
                
                for(int i=2;i<=500;i++){
                    
                    if(fib[i].compareTo(a)>=0&&fib[i].compareTo(b)<=0)counter++;
                }
                
                System.out.println(counter);
            }
        }
    }
}