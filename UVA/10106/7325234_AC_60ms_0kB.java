//package lab.assignment;
import java.util.*;
import java.math.*;
class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger a , b;
        
        while(sc.hasNext()){
            
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            
            System.out.println(a.multiply(b));
        }
    }
} 