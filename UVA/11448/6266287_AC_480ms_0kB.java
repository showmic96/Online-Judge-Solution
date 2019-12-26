import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        
        BigInteger in1 = new BigInteger("0");
        BigInteger in2 = new BigInteger("0");
        for(int b=0;b<a;b++){
            
            in1 = sc.nextBigInteger();
            in2 = sc.nextBigInteger();
            
            in1=in1.subtract(in2);
            
            System.out.println(in1);
            
        }
    }
}