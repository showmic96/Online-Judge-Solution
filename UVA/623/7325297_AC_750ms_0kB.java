//package lab.assignment;
import java.util.*;
import java.math.*;
class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigDecimal a , b;
        
        while(sc.hasNext()){
            
            int c = sc.nextInt();
            a = new BigDecimal("1");
            for(int i=1;i<=c;i++){
                
                a = a.multiply(BigDecimal.valueOf(i));
            }
            
            System.out.println(c + "!");
            System.out.println(a.toPlainString());
        }
    }
} 