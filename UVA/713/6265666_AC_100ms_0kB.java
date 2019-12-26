import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        int c;
        
        c = sc.nextInt();
        
        for(int d=0;d<c;d++){
            
            a=sc.nextBigInteger();
            
            String ar = a.toString();
            String reverse = new StringBuffer(ar).reverse().toString();
            
            BigInteger k = new BigInteger(reverse);
            
            a=sc.nextBigInteger();
            
            ar = a.toString();
            reverse = new StringBuffer(ar).reverse().toString();
            
            BigInteger l = new BigInteger(reverse);
            
            l = l.add(k);
            
            ar = l.toString();
            reverse = new StringBuffer(ar).reverse().toString();
            BigInteger o = new BigInteger(reverse);
            System.out.println(o);
            
        }
        
    }
}