import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            
            BigInteger a = new BigInteger("0");
            BigInteger b = new BigInteger("0");
            char c;
            
            a = sc.nextBigInteger();
            c = sc.next(".").charAt(0);
            b=sc.nextBigInteger();
            
            if(c=='/')System.out.println(a.divide(b));
            else System.out.println(a.mod(b));
            
            
        }
    }
}