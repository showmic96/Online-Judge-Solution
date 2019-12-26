import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner (System.in);
        
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        BigInteger k = new BigInteger("0");
        char c;
        int d;
        
        String ar ,br;
        
        while(sc.hasNext()){
            
            ar=sc.next();
            c = sc.next().charAt(0);
            br=sc.next();
            a = new BigInteger(ar);
            b = new BigInteger(br);
            
            if(c=='+'){k=a;k=k.add(b);}
            else {k=a;k=k.multiply(b);}
            
            System.out.println(ar + " " + c+" " + br);
            d=a.intValue();
            if(a.compareTo(BigInteger.valueOf(d))!=0)System.out.println("first number too big");
            d=b.intValue();
            if(b.compareTo(BigInteger.valueOf(d))!=0)System.out.println("second number too big");
            d=k.intValue();
            if(k.compareTo(BigInteger.valueOf(d))!=0)System.out.println("result too big");
        }
    }
}