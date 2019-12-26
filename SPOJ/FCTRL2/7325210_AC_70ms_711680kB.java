//package lab.assignment;
import java.util.*;
import java.math.*;
class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        int a  = sc.nextInt();
        
        BigInteger ar;
        
        for(int i=0;i<a;i++){
            
            ar = new BigInteger("1");
            int b = sc.nextInt();
            
            for(int j=2;j<=b;j++){
                
                ar = ar.multiply(BigInteger.valueOf(j));
            }
            
            System.out.println(ar);
        }
    }
}