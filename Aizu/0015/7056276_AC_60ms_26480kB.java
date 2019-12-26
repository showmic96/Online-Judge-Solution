
import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        
        BigInteger ar = new BigInteger("0");
        BigInteger br = new BigInteger("0");
        
        for(int i=1;i<=a;i++){
            
            ar = sc.nextBigInteger();
            br = sc.nextBigInteger();
            
            if(ar.toString().length()>80)System.out.println("overflow");
            else if(br.toString().length()>80)System.out.println("overflow");
            else if(ar.add(br).toString().length()>80)System.out.println("overflow");
            else System.out.println(ar.add(br));
        }
        
        
        
    }
}