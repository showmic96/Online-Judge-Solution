import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("0");
        for(;;){
        
        
        a = sc.nextBigInteger();
        if(a.compareTo(c)==0)break;
        b = b.add(a);
        }
        System.out.println(b);
        //a=BigInteger.ZERO;
        
    }
  //  }
}
