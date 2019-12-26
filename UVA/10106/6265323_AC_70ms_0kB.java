import java.util.*;
import java.math.*;
class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("1");
        BigInteger d = new BigInteger("2");
        
        while(sc.hasNext()){
            
            b=sc.nextBigInteger();
            c=sc.nextBigInteger();
            
            b=b.multiply(c);
            System.out.println(b);
            
            
            
            
        }
        
    }
}