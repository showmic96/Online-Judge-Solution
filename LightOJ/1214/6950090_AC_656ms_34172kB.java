//package lab.assignment;

import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        
        BigInteger big1 , big2;
        
        for(int i=0;i<a;i++){
            
            big1 = sc.nextBigInteger();
            big2 = sc.nextBigInteger();
            big1 = big1.abs();
            big2 = big2.abs();
            
            System.out.printf("Case %d: ",i+1);
            if(big1.mod(big2).compareTo(BigInteger.valueOf(0))==0)System.out.print("divisible");
            else System.out.print("not divisible");
            
            System.out.println();
        }
    }
}
    