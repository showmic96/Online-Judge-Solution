import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger a = new BigInteger("0");
        int j = 0;
        while(sc.hasNext()){
            
            if(j==1)System.out.println();j=1;
            
            a = sc.nextBigInteger();
            
            if(a.mod(BigInteger.valueOf(400)).compareTo(BigInteger.valueOf(0))==0||(a.mod(BigInteger.valueOf(4)).compareTo(BigInteger.valueOf(0))==0&&a.mod(BigInteger.valueOf(100)).compareTo(BigInteger.valueOf(0))!=0)){
                
                System.out.println("This is leap year.");
                
                if(a.mod(BigInteger.valueOf(15)).compareTo(BigInteger.valueOf(0))==0)System.out.println("This is huluculu festival year.");
                if(a.mod(BigInteger.valueOf(55)).compareTo(BigInteger.valueOf(0))==0)System.out.println("This is bulukulu festival year.");
                
            
            }
            
            else if(a.mod(BigInteger.valueOf(15)).compareTo(BigInteger.valueOf(0))==0)System.out.println("This is huluculu festival year.");
            else System.out.println("This is an ordinary year.");
            
            
            
        }
    }
}