
import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        
        BigInteger ar = new BigInteger("1");
        
        for(int i=1;i<=a;i++){
            
            ar = ar.multiply(BigInteger.valueOf(i));
        }
        
        System.out.println(ar);
        
    }
}