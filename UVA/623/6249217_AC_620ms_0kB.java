import java.util.*;
import java.math.*;
class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("17");
        
        while(sc.hasNext()){
            
            BigInteger a = new BigInteger("1");
            long k = sc.nextLong();
            //a = sc.nextBigInteger();
            for(long j=k;j>1;j--){
                
                a=a.multiply(BigInteger.valueOf(j));
            }
            
            
            
            
            System.out.println(k + "!");
            System.out.println(a);
            
        }
        
    }
}