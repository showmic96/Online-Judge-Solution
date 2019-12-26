import java.util.*;
import java.math.*;
class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("17");
        
        while(sc.hasNext()){
            
            BigInteger a = new BigInteger("0");
            a = sc.nextBigInteger();
            if(a.compareTo(b)==0)break;
            
            
            
            if(a.mod(c).compareTo(b)==0)System.out.println("1");
            else System.out.println("0");
            
        }
        
    }
}