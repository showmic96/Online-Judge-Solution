// In the name of Allah the Most Merciful

import java.util.*;
import java.math.*;

public class Main {
    
    static boolean isLeapYear(BigInteger a){
        
        if(a.mod(BigInteger.valueOf(400)).compareTo(BigInteger.valueOf(0))==0)return true;
        
        if(a.mod(BigInteger.valueOf(4)).compareTo(BigInteger.ZERO)==0&&a.mod(BigInteger.valueOf(100)).compareTo(BigInteger.ZERO)!=0)return true;
        
        return false;
    }
    
    static boolean isHuluculu(BigInteger a){
        
        if(a.mod(BigInteger.valueOf(15)).compareTo(BigInteger.ZERO)==0)return true;
        return false;
    }
    
    static boolean isBulukulu(BigInteger a){
        
        if(a.mod(BigInteger.valueOf(55)).compareTo(BigInteger.ZERO)==0)return true;
        return false;
    }

    
    public static void main(String arg[]){
    
        Scanner sc = new Scanner(System.in);
        boolean space = false;
        while(sc.hasNext()){
            if(space)System.out.println();
            boolean check = false;
            
            BigInteger a = sc.nextBigInteger();
            
            if(isLeapYear(a)==true){check=true;System.out.println("This is leap year.");}
            if(isHuluculu(a)==true){check=true;System.out.println("This is huluculu festival year.");}
            if(isBulukulu(a)==true&&isLeapYear(a)==true){check=true;System.out.println("This is bulukulu festival year.");}
            
            if(check==false)System.out.println("This is an ordinary year.");
            
            space = true;
        }
    }
} 