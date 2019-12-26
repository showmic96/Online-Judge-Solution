// In the name of Allah the Most Merciful

import java.util.*;
import java.math.*;
public class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        BigInteger a;
        int b;
        while(sc.hasNext()){
            
            a = sc.nextBigInteger();
            b = sc.nextInt();
            
            if(a.compareTo(BigInteger.ZERO)==0&&b==0)break;
            
            System.out.println(a.pow(b));
        }
    }
    
} 